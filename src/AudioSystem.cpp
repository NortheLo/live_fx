#include "../lib/AudioSystem.hpp"

#include <iostream>
#include <string>

AudioSystem::AudioSystem() {
    err = Pa_Initialize();
    if (err != paNoError) {
        printErr(err);
    }
    getDevice();
}

AudioSystem::~AudioSystem() {
    closeAudio();
}

void AudioSystem::printErr(PaError err) {
    std::cerr << "ERROR: %s", Pa_GetErrorText(err);
    closeAudio();
}

void AudioSystem::getDevice() {

    inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
    inputInfo = Pa_GetDeviceInfo( inputParameters.device );
    inputParameters.channelCount = numChannels;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = inputInfo->defaultLowInputLatency ;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
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
    err = Pa_OpenStream(
            &stream,
            &inputParameters,
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,      /* we won't output out of range samples so don't bother clipping them */
            NULL, /* no callback, use blocking API */
            NULL ); /* no callback, so no callback userData */

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
}