# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/louis/Dokumente/Programmieren/C++/live_fx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/louis/Dokumente/Programmieren/C++/live_fx/build

# Include any dependencies generated for this target.
include CMakeFiles/live_fx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/live_fx.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/live_fx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/live_fx.dir/flags.make

CMakeFiles/live_fx.dir/src/main.o: CMakeFiles/live_fx.dir/flags.make
CMakeFiles/live_fx.dir/src/main.o: /home/louis/Dokumente/Programmieren/C++/live_fx/src/main.cpp
CMakeFiles/live_fx.dir/src/main.o: CMakeFiles/live_fx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/louis/Dokumente/Programmieren/C++/live_fx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/live_fx.dir/src/main.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/live_fx.dir/src/main.o -MF CMakeFiles/live_fx.dir/src/main.o.d -o CMakeFiles/live_fx.dir/src/main.o -c /home/louis/Dokumente/Programmieren/C++/live_fx/src/main.cpp

CMakeFiles/live_fx.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/live_fx.dir/src/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/louis/Dokumente/Programmieren/C++/live_fx/src/main.cpp > CMakeFiles/live_fx.dir/src/main.i

CMakeFiles/live_fx.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/live_fx.dir/src/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/louis/Dokumente/Programmieren/C++/live_fx/src/main.cpp -o CMakeFiles/live_fx.dir/src/main.s

CMakeFiles/live_fx.dir/src/AudioSystem.o: CMakeFiles/live_fx.dir/flags.make
CMakeFiles/live_fx.dir/src/AudioSystem.o: /home/louis/Dokumente/Programmieren/C++/live_fx/src/AudioSystem.cpp
CMakeFiles/live_fx.dir/src/AudioSystem.o: CMakeFiles/live_fx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/louis/Dokumente/Programmieren/C++/live_fx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/live_fx.dir/src/AudioSystem.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/live_fx.dir/src/AudioSystem.o -MF CMakeFiles/live_fx.dir/src/AudioSystem.o.d -o CMakeFiles/live_fx.dir/src/AudioSystem.o -c /home/louis/Dokumente/Programmieren/C++/live_fx/src/AudioSystem.cpp

CMakeFiles/live_fx.dir/src/AudioSystem.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/live_fx.dir/src/AudioSystem.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/louis/Dokumente/Programmieren/C++/live_fx/src/AudioSystem.cpp > CMakeFiles/live_fx.dir/src/AudioSystem.i

CMakeFiles/live_fx.dir/src/AudioSystem.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/live_fx.dir/src/AudioSystem.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/louis/Dokumente/Programmieren/C++/live_fx/src/AudioSystem.cpp -o CMakeFiles/live_fx.dir/src/AudioSystem.s

# Object files for target live_fx
live_fx_OBJECTS = \
"CMakeFiles/live_fx.dir/src/main.o" \
"CMakeFiles/live_fx.dir/src/AudioSystem.o"

# External object files for target live_fx
live_fx_EXTERNAL_OBJECTS =

live_fx: CMakeFiles/live_fx.dir/src/main.o
live_fx: CMakeFiles/live_fx.dir/src/AudioSystem.o
live_fx: CMakeFiles/live_fx.dir/build.make
live_fx: CMakeFiles/live_fx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/louis/Dokumente/Programmieren/C++/live_fx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable live_fx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/live_fx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/live_fx.dir/build: live_fx
.PHONY : CMakeFiles/live_fx.dir/build

CMakeFiles/live_fx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/live_fx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/live_fx.dir/clean

CMakeFiles/live_fx.dir/depend:
	cd /home/louis/Dokumente/Programmieren/C++/live_fx/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/louis/Dokumente/Programmieren/C++/live_fx /home/louis/Dokumente/Programmieren/C++/live_fx /home/louis/Dokumente/Programmieren/C++/live_fx/build /home/louis/Dokumente/Programmieren/C++/live_fx/build /home/louis/Dokumente/Programmieren/C++/live_fx/build/CMakeFiles/live_fx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/live_fx.dir/depend

