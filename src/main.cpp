#include <iostream>
#include <unistd.h> // For UNIX sleep function; deprectaded but could be useful for OpenBSD port

#include "../lib/AudioSystem.hpp"
#include "../lib/LowPass.hpp"
#include "../lib/Window.hpp"


int main(int argc, char *argv[]) {
    //auto app = Gtk::Application::create("org.gtkmm.examples.base");

    float* buf;
    AudioSystem audio = AudioSystem();
    audio.openAudio();

    //Needs testing
    LowPass lp = LowPass(0.1f);

    //app->make_window_and_run<MainWindow>(argc, argv);
    

    while(Pa_IsStreamActive(audio.stream)) {

        buf = audio.getBuffer();
        for(size_t i = 0; i < 256; i++) {
            lp.applyEffect(buf[i], buf[i]);
        }

        audio.writeBuffer(buf, 256);
        usleep(1); 
    }

    std::cout << "End\n";
    return EXIT_SUCCESS;
}