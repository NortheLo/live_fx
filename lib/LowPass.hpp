#pragma once

#include "AudioFX.hpp"

#define ORDER 3

typedef struct {
    float a0 = 1;
    float a1 = 2;
    float a2 = 2;
    float a3 = 1;
} butterCoeff;

class LowPass : public AudioFX
{
    private:
        int samplingFrequency = 48e3;
        float angularFreq = 0;
        float poles[ORDER] = {0};

    public:
        LowPass(float freq, int samplingFrq) : angularFreq(freq), samplingFrequency(samplingFrq) {} 

        ~LowPass();

        void setPoles(float pole[ORDER]);
        void setAngularFreq(float frq);

        float* getPoles() { return poles; }
        float getAngularFreq() { return angularFreq; }

        float* applyEffect() override;
        
};

