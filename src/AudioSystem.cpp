#include "../lib/AudioSystem.hpp"

#include <iostream>
#include <string>

AudioSystem::AudioSystem() {
    err = Pa_Initialize();
    if (err != paNoError) {
        printErr(err);
    }

    selDev();
}

AudioSystem::~AudioSystem() {
    closeAudio();
}

void AudioSystem::printErr(PaError err) {
    std::cerr << "ERROR: " << Pa_GetErrorText(err) << "\n";
    closeAudio();
}

int AudioSystem::printDev() {
    int devices = Pa_GetDeviceCount();

    for (int i = 0; i != devices; ++i) 
    {
        auto * info = Pa_GetDeviceInfo(i);
        std::cout << "ID: " << i << " " << info->name << std::endl;
    } 
    return devices;
}

void AudioSystem::selDev() {
    int devID;
    int devNum = printDev();
   
    do {
        std::cout << "Select device by ID number (0 will use system defaults): ";
        std::cin >> devID; 
    } while (devID > devNum);
    
    setDevices(devID);
}

void AudioSystem::setDevices(int devID) {

    if (devID == 0)
    {
        inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
        outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */

    }
    else {
        inputParameters.device = devID;
        outputParameters.device = devID;
    }

    inputInfo = Pa_GetDeviceInfo( inputParameters.device );
    inputParameters.channelCount = numChannels;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = inputInfo->defaultLowInputLatency ;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputInfo = Pa_GetDeviceInfo( outputParameters.device );
    outputParameters.channelCount = numChannels;
    outputParameters.sampleFormat = PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = outputInfo->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;    
    
    std::cout << "+++INFO+++\nDevice ID{i:o}: " << inputParameters.device << " " << outputParameters.device << "\n";
    std::cout << "Name{i:o}: " << inputInfo->name << " " <<  outputInfo->name << "\n";
    std::cout << "Latency:{i:o}: " << inputInfo->defaultLowInputLatency << " " << outputInfo->defaultLowOutputLatency << "\n";
    
}

int AudioSystem::openAudio() {
    err = Pa_OpenStream(&stream,
                        &inputParameters,
                        &outputParameters,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        paClipOff,              /* we won't output out of range samples so don't bother clipping them */
                        &AudioSystem::streamCallback,                
                        nullptr);               /* no callback, so no callback userData */

    if (err != paNoError && Pa_StartStream(stream) != paNoError) {
        printErr(err);
        return -1;
    }

    return 0;
}

void AudioSystem::closeAudio() {
    Pa_AbortStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    exit(EXIT_FAILURE);
}

int AudioSystem::audioCallback(const void *inputBuffer,
                                void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo,
                                PaStreamCallbackFlags statusFlags) {
                        
    /* Needs its implementation */
    inData = (float*) inputBuffer;
    outData = (float*) outputBuffer;

    counter++;

    return paContinue;
}

float* AudioSystem::getInData() {
    return inData;
}

float* AudioSystem::getOutData() {
    return outData;
}
