#pragma once

#include <cmath>
#include <memory>

class LowPass
{
    private:
        struct thirdButterLPTCoeff { float a0, a1, a2, a3, b1, b2, b3; };
        thirdButterLPTCoeff coeff{};
        float wc = 0.2f;
        float K, norm;
        float p0, p1, p2, z1, z2, z3;

    public:
        LowPass(float wc);

        ~LowPass();

        void setFreq(float wc);

        void applyEffect(float input, float &output);
};
