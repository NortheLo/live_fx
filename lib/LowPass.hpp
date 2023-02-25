#pragma once

#include "AudioFX.hpp"
#include <cmath>

typedef struct {
    float a0, a1, a2, a3, b1, b2, b3;
} thirdButterLPTCoeff;

class LowPass : public AudioFX
{
    private:
        float wc = 0.2f;
        float K, norm;
        thirdButterLPTCoeff *coeff;
        float p0, p1, p2, z1, z2, z3;

    public:
        LowPass(float wc) : wc(wc) {
            setFreq(wc);
        } 

        ~LowPass();

        void setFreq(float wc);

        void applyEffect(float input, float &output) override;
        
};

