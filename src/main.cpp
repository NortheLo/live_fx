#include <iostream>
#include <math.h>
#include <unistd.h> // For UNIX sleep func
#include "../lib/AudioSystem.hpp"

int main() {
    /* Test sin signal for output */
    float testSignal[256];
    for (size_t i = 0; i < 256; i++)
    {
        testSignal[i] = sin(M_PI * i / 256);
        std::cout << testSignal[i] << " ";
    }
    
    float* buf;
    
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    while(Pa_IsStreamActive(audio.stream)) {

        buf = audio.getBuffer();
        audio.writeBuffer(buf, 256);
        usleep(1); 
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}