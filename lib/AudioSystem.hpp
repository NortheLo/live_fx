#pragma once
#include <iostream> // for debugging
#include "portaudio.h"

#define SAMPLE_RATE       48000
#define FRAMES_PER_BUFFER   256
#define PA_SAMPLE_TYPE paFloat32

typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    float*       recordedSamples;
} audioBuffer;

class AudioSystem
{
    private:
        PaStreamParameters inputParameters, outputParameters;
        const PaDeviceInfo* inputInfo;
        const PaDeviceInfo* outputInfo;
        int numChannels = 1;
        audioBuffer *data;

        float* inData = nullptr;   

        void printErr(PaError err);
        void setDevices(int devID);
        int printDev();
        void selDev();
        static int streamCallback(const void *inputBuffer, void *outputBuffer,
                                  unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                                  PaStreamCallbackFlags statusFlags, void *userData) {
            return ((AudioSystem*)userData)->audioCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags, userData);
        }

        int audioCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags, void *userData);

    public:
        AudioSystem();
        ~AudioSystem();
        PaStream *stream = nullptr;   
             
        int openAudio();
        void closeAudio(int quit);
        float* getBuffer() { return inData; }

};

