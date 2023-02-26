#include <iostream>
#include <unistd.h> // For UNIX sleep function; deprectaded but could be useful for OpenBSD port
#include <cmath>

#include "../lib/AudioSystem.hpp"
#include "../lib/LowPass.hpp"
#include "../lib/Window.hpp"


int main(int argc, char *argv[]) {
    //auto app = Gtk::Application::create("org.gtkmm.examples.base");

    //Testing the lp 
    int nmSam = 256;
    float sinbuf[nmSam] = {0};
    float fq = 10;
    for (size_t i = 0; i < nmSam; i++) {
        sinbuf[i] = std::sin(i*fq);
    }

    float wc = 0.1f;
    LowPass lp = LowPass(wc);

    for (size_t j = 0; j < nmSam; j++) {
        std::cout << sinbuf[j] << "  ";
        lp.applyEffect(sinbuf[j], sinbuf[j]);
        std::cout << sinbuf[j] << "\n";
    }


    float* buf;
    //AudioSystem audio = AudioSystem();
    //audio.openAudio();

    //app->make_window_and_run<MainWindow>(argc, argv);
    
/*
    while(Pa_IsStreamActive(audio.stream)) {

        buf = audio.getBuffer();
        for(size_t i = 0; i < 256; i++) {
            lp.applyEffect(buf[i], buf[i]);
        }

        audio.writeBuffer(buf, 256);
        usleep(1); 
    }
*/

    std::cout << "End\n";
    return EXIT_SUCCESS;
}