#include "../lib/LowPass.hpp"

LowPass::LowPass(float wc) : wc(wc) {
            setFreq(wc);
} 

LowPass::~LowPass() { }

void LowPass::setFreq(float wc) {
    K = std::tan(M_PI * wc);
    norm = 1 / (pow(K, 3) + 2 * pow(K, 2) + 2 * K + 1);
    coeff.a0 = pow(K, 3) * norm;
    coeff.a1 = 3 * coeff.a0;
    coeff.a2 = coeff.a1;
    coeff.a3 = coeff.a0;
    coeff.b1 = (3 * pow(K, 3) + 2 * pow(K, 2) - 2 * K - 3) * norm;
    coeff.b2 = (3 * pow(K, 3) - 2 * pow(K, 2) - 2 * K + 3) * norm;
    coeff.b3 = (pow(K, 3) - 2 * pow(K, 2) + 2 * K - 1) * norm; 
}

void LowPass::applyEffect(float input, float &output) {
    output = input * coeff.a1 + z1;
    output = input * coeff.a0 + z1;
    z1 = input * coeff.a1 + z2 - coeff.b1 * output;
    z2 = input * coeff.a2 + z3 - coeff.b2 * output;
    z3 = input * coeff.a3 - coeff.b3 * output;
    p0 = p1; p1 = p2; p2 = input;
}