#include <iostream>
#include <unistd.h> // For UNIX sleep function; deprectaded but could be useful for OpenBSD port
#include <cmath>

#include "../include/AudioSystem.hpp"
#include "../include/LowPass.hpp"
#include "../include/Window.hpp"


int main(int argc, char *argv[]) {
    //Testing the lp 
    int nmSam = 256;
    float sinbuf[nmSam] = {0};
    float fq = 10;
    for (size_t i = 0; i < nmSam; i++) {
        sinbuf[i] = std::sin(i*fq);
    }

    float wc = 0.5f;
    LowPass lp = LowPass(wc);

    for (size_t j = 0; j < nmSam; j++) {
        std::cout << sinbuf[j] << "  ";
        lp.applyEffect(sinbuf[j], sinbuf[j]);
        std::cout << sinbuf[j] << "\n";
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}