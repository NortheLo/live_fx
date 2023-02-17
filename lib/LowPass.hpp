#pragma once

#include "AudioFX.hpp"

#define ORDER 5

class LowPass : AudioFX
{
    private:
        float angularFreq = 0;
        float poles[ORDER] = {0};

    public:
        LowPass(float freq, float pole[ORDER]);
        ~LowPass();

        void setPoles(float pole[ORDER]);
        void setAngularFreq(float frq);

        float* getPoles();
        float getAngularFreq();
};

