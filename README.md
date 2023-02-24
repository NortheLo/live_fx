# About  
This project should be a simple program, which reads input from an input device like your soundcard and apply a audio filter and monitor it to a desired output. 

## Build
Step 1: Create build directory  ``mkdir build && cd build``  
Step 2: Create makefile and build with   ``cmake .. && make``  

## To-Do:
### Build:
 - [ ] Add CMake Flags for Release Mode with -O2/-O3 Optimization  
### GUI: 
 - [ ] Design Main-Window with Glade
 - [ ] Implement independant in-/output device selector
### Filter:
 - [ ] Implement simple LP filter

## Dependencies:
All of the dependencies should be included in your distributors repos since all of them are quite standard packages for audio and gui programs. On OpenBSD those packages should be available under x11/ and audio/.
 - PortAudio
 - gtkmm & glibmm 