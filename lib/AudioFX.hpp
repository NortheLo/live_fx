#pragma once

#include <math.h>

/* Abstract class for audio effects */

class AudioFX
{
    private:
        
    public:
        virtual ~AudioFX();
        
        virtual float* applyEffect() = 0;
        
};

