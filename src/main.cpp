#include <iostream>
#include "../lib/AudioSystem.hpp"

int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    for(int i = 0; i < 50; i++){
        std::cout << "In-Data: " << audio.getInData() << "\n";
        std::cout << "Out-Data: " << audio.getOutData() << "\n";
    }
    std::cout << "End\n";
    return EXIT_SUCCESS;
}