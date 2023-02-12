#pragma once
#include "portaudio.h"

#define SAMPLE_RATE       44100
#define FRAMES_PER_BUFFER   512
#define PA_SAMPLE_TYPE paFloat32

typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    float      *recordedSamples;
} audioBuffer;

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
        audioBuffer *data;

        void printErr(PaError err);
        void setDevices(int devID);
        int printDev();
        void selDev();
        static int streamCallback(const void *inputBuffer,
                            void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo *timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void *userData) {
            return ((AudioSystem*)userData)->audioCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags, userData);
        }

        int audioCallback(const void *inputBuffer,
                                void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo,
                                PaStreamCallbackFlags statusFlags, void *userData);

    public:
        int counter = 0; //debugging variable; pls remove after fix
        AudioSystem();
        ~AudioSystem();
        
        int openAudio();
        void closeAudio();
};

