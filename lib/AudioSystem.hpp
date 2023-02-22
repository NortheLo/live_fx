#pragma once

#include <mutex>
#include <atomic>
#include "portaudio.h"

#define SAMPLE_RATE       48000
#define FRAMES_PER_BUFFER   256
#define PA_SAMPLE_TYPE paFloat32

class AudioSystem
{
    private:
        PaStreamParameters inputParameters, outputParameters;
        const PaDeviceInfo* inputInfo;
        const PaDeviceInfo* outputInfo;
        int numChannels = 1;
        /* Double buffering when reading the input data */ 
        float frontBuffer[FRAMES_PER_BUFFER];  
        std::mutex mu;
        std::atomic<bool> rdy = false;

        void printErr(PaError err);
        void setDevices(int devID);
        int printDev();
        void selDev();
        static int streamCallback(const void *inputBuffer, void *outputBuffer,
                                  unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                                  PaStreamCallbackFlags statusFlags, void *userData) {

            return ((AudioSystem*)userData)->audioCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags); 
        }

        int audioCallback(const void *inputBuffer, void *outputBuffer,
                                  unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                                  PaStreamCallbackFlags statusFlags);
    public:
        AudioSystem();
        ~AudioSystem();
        PaStream *stream = nullptr;   
        long cnt = 0;    
        
        int openAudio();
        void closeAudio(int quit);
        void getBuffer();
        void writeBuffer();

};

