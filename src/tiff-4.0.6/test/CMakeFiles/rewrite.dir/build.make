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
include test/CMakeFiles/rewrite.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/rewrite.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/rewrite.dir/flags.make

test/CMakeFiles/rewrite.dir/rewrite_tag.c.o: test/CMakeFiles/rewrite.dir/flags.make
test/CMakeFiles/rewrite.dir/rewrite_tag.c.o: test/rewrite_tag.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object test/CMakeFiles/rewrite.dir/rewrite_tag.c.o"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/rewrite_tag.c.o   -c /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test/rewrite_tag.c

test/CMakeFiles/rewrite.dir/rewrite_tag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/rewrite_tag.c.i"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test/rewrite_tag.c > CMakeFiles/rewrite.dir/rewrite_tag.c.i

test/CMakeFiles/rewrite.dir/rewrite_tag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/rewrite_tag.c.s"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test/rewrite_tag.c -o CMakeFiles/rewrite.dir/rewrite_tag.c.s

test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.requires:
.PHONY : test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.requires

test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.provides: test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.requires
	$(MAKE) -f test/CMakeFiles/rewrite.dir/build.make test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.provides.build
.PHONY : test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.provides

test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.provides.build: test/CMakeFiles/rewrite.dir/rewrite_tag.c.o

# Object files for target rewrite
rewrite_OBJECTS = \
"CMakeFiles/rewrite.dir/rewrite_tag.c.o"

# External object files for target rewrite
rewrite_EXTERNAL_OBJECTS =

test/rewrite: test/CMakeFiles/rewrite.dir/rewrite_tag.c.o
test/rewrite: test/CMakeFiles/rewrite.dir/build.make
test/rewrite: libtiff/libtiff.so.5.2.4
test/rewrite: port/libport.a
test/rewrite: /usr/lib/x86_64-linux-gnu/libm.so
test/rewrite: /usr/lib/x86_64-linux-gnu/libz.so
test/rewrite: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/rewrite: /usr/lib/x86_64-linux-gnu/libjbig.so
test/rewrite: /usr/lib/x86_64-linux-gnu/liblzma.so
test/rewrite: test/CMakeFiles/rewrite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable rewrite"
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rewrite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/rewrite.dir/build: test/rewrite
.PHONY : test/CMakeFiles/rewrite.dir/build

test/CMakeFiles/rewrite.dir/requires: test/CMakeFiles/rewrite.dir/rewrite_tag.c.o.requires
.PHONY : test/CMakeFiles/rewrite.dir/requires

test/CMakeFiles/rewrite.dir/clean:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test && $(CMAKE_COMMAND) -P CMakeFiles/rewrite.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/rewrite.dir/clean

test/CMakeFiles/rewrite.dir/depend:
	cd /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6 /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test /home/gbrunner/Documents/Programmation/SWWsimulator/src/tiff-4.0.6/test/CMakeFiles/rewrite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/rewrite.dir/depend

