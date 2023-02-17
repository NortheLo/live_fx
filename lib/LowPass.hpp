#pragma once

#include "AudioFX.hpp"

#define ORDER 5

class LowPass : public AudioFX
{
    private:
        float angularFreq = 0;
        float poles[ORDER] = {0};

    public:
        LowPass(float freq) : angularFreq(freq) {} 

        ~LowPass();

        void setPoles(float pole[ORDER]);
        void setAngularFreq(float frq);

        float* getPoles() { return poles; }
        float getAngularFreq() { return angularFreq; }

        float* applyEffect() override ;
        
};

