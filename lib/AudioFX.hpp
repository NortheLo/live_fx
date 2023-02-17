#pragma once

/* Abstract class for audio effects */

class AudioFX
{
    private:
        
    public:
        virtual ~AudioFX();
        
        virtual float* applyEffect() = 0;
        
};

