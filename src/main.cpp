#include <iostream>
#include "../lib/AudioSystem.hpp"


int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    while(Pa_IsStreamActive(audio.stream)) {
        // if ready flag
        float* buf = audio.getBuffer();

    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}