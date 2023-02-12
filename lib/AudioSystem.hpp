#pragma once
#include "portaudio.h"

#define SAMPLE_RATE       44100
#define FRAMES_PER_BUFFER   512
#define PA_SAMPLE_TYPE paFloat32

class AudioSystem
{
    private:
        PaStreamParameters inputParameters, outputParameters;
        PaStream *stream = nullptr;
        PaError err;
        const PaDeviceInfo* inputInfo;
        const PaDeviceInfo* outputInfo;
        char* sampleBlock = nullptr;
        int numBytes;
        int numChannels = 1;
        float* inData = nullptr;
        float* outData = nullptr;

        void printErr(PaError err);
        void setDevices(int devID);
        void printDev();
        void selDev();
        static int streamCallback(const void *inputBuffer,
                            void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData) {
            return ((AudioSystem*)userData)->audioCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);
        }

        int audioCallback(const void *inputBuffer,
                                void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo,
                                PaStreamCallbackFlags statusFlags);

    public:
        AudioSystem();
        ~AudioSystem();
        
        int openAudio();
        void closeAudio();
        float* getInData();
        float* getOutData();
        
};

