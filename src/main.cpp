#include <iostream>
#include "../lib/AudioSystem.hpp"


int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    while(true) {
        std::cout << audio.counter << "\n";
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}