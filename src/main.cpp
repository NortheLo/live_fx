#include <iostream>
#include <unistd.h> // For UNIX sleep function; deprectaded but could be useful for OpenBSD port

#include "../lib/AudioSystem.hpp"

#include "../lib/Window.hpp"


int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    return app->make_window_and_run<MainWindow>(argc, argv);

    /*
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
    */
}