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
include tools/CMakeFiles/tiff2rgba.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/tiff2rgba.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/tiff2rgba.dir/flags.make

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o: tools/CMakeFiles/tiff2rgba.dir/flags.make
tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o: tools/tiff2rgba.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o   -c /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiff2rgba.c

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tiff2rgba.dir/tiff2rgba.c.i"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiff2rgba.c > CMakeFiles/tiff2rgba.dir/tiff2rgba.c.i

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tiff2rgba.dir/tiff2rgba.c.s"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiff2rgba.c -o CMakeFiles/tiff2rgba.dir/tiff2rgba.c.s

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.requires:
.PHONY : tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.requires

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.provides: tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.requires
	$(MAKE) -f tools/CMakeFiles/tiff2rgba.dir/build.make tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.provides.build
.PHONY : tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.provides

tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.provides.build: tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o

# Object files for target tiff2rgba
tiff2rgba_OBJECTS = \
"CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o"

# External object files for target tiff2rgba
tiff2rgba_EXTERNAL_OBJECTS =

tools/tiff2rgba: tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o
tools/tiff2rgba: tools/CMakeFiles/tiff2rgba.dir/build.make
tools/tiff2rgba: libtiff/libtiff.so.5.2.4
tools/tiff2rgba: port/libport.a
tools/tiff2rgba: /usr/lib/x86_64-linux-gnu/libm.so
tools/tiff2rgba: /usr/lib/x86_64-linux-gnu/libz.so
tools/tiff2rgba: /usr/lib/x86_64-linux-gnu/libjpeg.so
tools/tiff2rgba: /usr/lib/x86_64-linux-gnu/libjbig.so
tools/tiff2rgba: /usr/lib/x86_64-linux-gnu/liblzma.so
tools/tiff2rgba: tools/CMakeFiles/tiff2rgba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable tiff2rgba"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiff2rgba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/tiff2rgba.dir/build: tools/tiff2rgba
.PHONY : tools/CMakeFiles/tiff2rgba.dir/build

tools/CMakeFiles/tiff2rgba.dir/requires: tools/CMakeFiles/tiff2rgba.dir/tiff2rgba.c.o.requires
.PHONY : tools/CMakeFiles/tiff2rgba.dir/requires

tools/CMakeFiles/tiff2rgba.dir/clean:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -P CMakeFiles/tiff2rgba.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/tiff2rgba.dir/clean

tools/CMakeFiles/tiff2rgba.dir/depend:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/CMakeFiles/tiff2rgba.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/tiff2rgba.dir/depend

