# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6

# Include any dependencies generated for this target.
include tools/CMakeFiles/pal2rgb.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/pal2rgb.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/pal2rgb.dir/flags.make

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o: tools/CMakeFiles/pal2rgb.dir/flags.make
tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o: tools/pal2rgb.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pal2rgb.dir/pal2rgb.c.o   -c /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/pal2rgb.c

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pal2rgb.dir/pal2rgb.c.i"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/pal2rgb.c > CMakeFiles/pal2rgb.dir/pal2rgb.c.i

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pal2rgb.dir/pal2rgb.c.s"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/pal2rgb.c -o CMakeFiles/pal2rgb.dir/pal2rgb.c.s

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.requires:
.PHONY : tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.requires

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.provides: tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.requires
	$(MAKE) -f tools/CMakeFiles/pal2rgb.dir/build.make tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.provides.build
.PHONY : tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.provides

tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.provides.build: tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o

# Object files for target pal2rgb
pal2rgb_OBJECTS = \
"CMakeFiles/pal2rgb.dir/pal2rgb.c.o"

# External object files for target pal2rgb
pal2rgb_EXTERNAL_OBJECTS =

tools/pal2rgb: tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o
tools/pal2rgb: tools/CMakeFiles/pal2rgb.dir/build.make
tools/pal2rgb: libtiff/libtiff.so.5.2.4
tools/pal2rgb: port/libport.a
tools/pal2rgb: /usr/lib/x86_64-linux-gnu/libm.so
tools/pal2rgb: /usr/lib/x86_64-linux-gnu/libz.so
tools/pal2rgb: /usr/lib/x86_64-linux-gnu/libjpeg.so
tools/pal2rgb: /usr/lib/x86_64-linux-gnu/libjbig.so
tools/pal2rgb: /usr/lib/x86_64-linux-gnu/liblzma.so
tools/pal2rgb: tools/CMakeFiles/pal2rgb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pal2rgb"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pal2rgb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/pal2rgb.dir/build: tools/pal2rgb
.PHONY : tools/CMakeFiles/pal2rgb.dir/build

tools/CMakeFiles/pal2rgb.dir/requires: tools/CMakeFiles/pal2rgb.dir/pal2rgb.c.o.requires
.PHONY : tools/CMakeFiles/pal2rgb.dir/requires

tools/CMakeFiles/pal2rgb.dir/clean:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -P CMakeFiles/pal2rgb.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/pal2rgb.dir/clean

tools/CMakeFiles/pal2rgb.dir/depend:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/CMakeFiles/pal2rgb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/pal2rgb.dir/depend
