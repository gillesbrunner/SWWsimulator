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
include tools/CMakeFiles/tiffmedian.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/tiffmedian.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/tiffmedian.dir/flags.make

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o: tools/CMakeFiles/tiffmedian.dir/flags.make
tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o: tools/tiffmedian.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tiffmedian.dir/tiffmedian.c.o   -c /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffmedian.c

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tiffmedian.dir/tiffmedian.c.i"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffmedian.c > CMakeFiles/tiffmedian.dir/tiffmedian.c.i

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tiffmedian.dir/tiffmedian.c.s"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/tiffmedian.c -o CMakeFiles/tiffmedian.dir/tiffmedian.c.s

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.requires:
.PHONY : tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.requires

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.provides: tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.requires
	$(MAKE) -f tools/CMakeFiles/tiffmedian.dir/build.make tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.provides.build
.PHONY : tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.provides

tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.provides.build: tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o

# Object files for target tiffmedian
tiffmedian_OBJECTS = \
"CMakeFiles/tiffmedian.dir/tiffmedian.c.o"

# External object files for target tiffmedian
tiffmedian_EXTERNAL_OBJECTS =

tools/tiffmedian: tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o
tools/tiffmedian: tools/CMakeFiles/tiffmedian.dir/build.make
tools/tiffmedian: libtiff/libtiff.so.5.2.4
tools/tiffmedian: port/libport.a
tools/tiffmedian: /usr/lib/x86_64-linux-gnu/libm.so
tools/tiffmedian: /usr/lib/x86_64-linux-gnu/libz.so
tools/tiffmedian: /usr/lib/x86_64-linux-gnu/libjpeg.so
tools/tiffmedian: /usr/lib/x86_64-linux-gnu/libjbig.so
tools/tiffmedian: /usr/lib/x86_64-linux-gnu/liblzma.so
tools/tiffmedian: tools/CMakeFiles/tiffmedian.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable tiffmedian"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiffmedian.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/tiffmedian.dir/build: tools/tiffmedian
.PHONY : tools/CMakeFiles/tiffmedian.dir/build

tools/CMakeFiles/tiffmedian.dir/requires: tools/CMakeFiles/tiffmedian.dir/tiffmedian.c.o.requires
.PHONY : tools/CMakeFiles/tiffmedian.dir/requires

tools/CMakeFiles/tiffmedian.dir/clean:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools && $(CMAKE_COMMAND) -P CMakeFiles/tiffmedian.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/tiffmedian.dir/clean

tools/CMakeFiles/tiffmedian.dir/depend:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/tools/CMakeFiles/tiffmedian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/tiffmedian.dir/depend

