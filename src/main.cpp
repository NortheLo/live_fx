#include <iostream>
#include "../lib/AudioSystem.hpp"


int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    while(Pa_IsStreamActive(audio.stream)) {

        audio.getBuffer();
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}