#include <iostream>
#include "../lib/AudioSystem.hpp"


int main() {
    AudioSystem audio = AudioSystem();
    audio.openAudio();
    
    while(Pa_IsStreamActive(audio.stream)) {
        // if ready flag
        float* buf = audio.getBuffer();
        for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
            //std::cout << i << " " << buf[i] << "\n";
        }
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}