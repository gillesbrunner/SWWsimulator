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
include tools/CMakeFiles/tiffdither.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/tiffdither.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/tiffdither.dir/flags.make

tools/CMakeFiles/tiffdither.dir/tiffdither.c.o: tools/CMakeFiles/tiffdither.dir/flags.make
tools/CMakeFiles/tiffdither.dir/tiffdither.c.o: tools/tiffdither.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tools/CMakeFiles/tiffdither.dir/tiffdither.c.o"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tiffdither.dir/tiffdither.c.o   -c /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffdither.c

tools/CMakeFiles/tiffdither.dir/tiffdither.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tiffdither.dir/tiffdither.c.i"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffdither.c > CMakeFiles/tiffdither.dir/tiffdither.c.i

tools/CMakeFiles/tiffdither.dir/tiffdither.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tiffdither.dir/tiffdither.c.s"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffdither.c -o CMakeFiles/tiffdither.dir/tiffdither.c.s

tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.requires:
.PHONY : tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.requires

tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.provides: tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.requires
	$(MAKE) -f tools/CMakeFiles/tiffdither.dir/build.make tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.provides.build
.PHONY : tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.provides

tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.provides.build: tools/CMakeFiles/tiffdither.dir/tiffdither.c.o

# Object files for target tiffdither
tiffdither_OBJECTS = \
"CMakeFiles/tiffdither.dir/tiffdither.c.o"

# External object files for target tiffdither
tiffdither_EXTERNAL_OBJECTS =

tools/tiffdither: tools/CMakeFiles/tiffdither.dir/tiffdither.c.o
tools/tiffdither: tools/CMakeFiles/tiffdither.dir/build.make
tools/tiffdither: libtiff/libtiff.so.5.2.4
tools/tiffdither: port/libport.a
tools/tiffdither: /usr/lib/x86_64-linux-gnu/libm.so
tools/tiffdither: /usr/lib/x86_64-linux-gnu/libz.so
tools/tiffdither: /usr/lib/x86_64-linux-gnu/libjpeg.so
tools/tiffdither: /usr/lib/x86_64-linux-gnu/libjbig.so
tools/tiffdither: /usr/lib/x86_64-linux-gnu/liblzma.so
tools/tiffdither: tools/CMakeFiles/tiffdither.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable tiffdither"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiffdither.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/tiffdither.dir/build: tools/tiffdither
.PHONY : tools/CMakeFiles/tiffdither.dir/build

tools/CMakeFiles/tiffdither.dir/requires: tools/CMakeFiles/tiffdither.dir/tiffdither.c.o.requires
.PHONY : tools/CMakeFiles/tiffdither.dir/requires

tools/CMakeFiles/tiffdither.dir/clean:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -P CMakeFiles/tiffdither.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/tiffdither.dir/clean

tools/CMakeFiles/tiffdither.dir/depend:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/CMakeFiles/tiffdither.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/tiffdither.dir/depend

