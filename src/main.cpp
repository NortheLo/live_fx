#include <iostream>
#include "../lib/AudioSystem.hpp"

int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    std::cout << "Hello";
    return EXIT_SUCCESS;
}