# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/lkit/Programming/C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lkit/Programming/C/build

# Include any dependencies generated for this target.
include CMakeFiles/main02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main02.dir/flags.make

CMakeFiles/main02.dir/main01.c.o: CMakeFiles/main02.dir/flags.make
CMakeFiles/main02.dir/main01.c.o: ../main01.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lkit/Programming/C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main02.dir/main01.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main02.dir/main01.c.o   -c /home/lkit/Programming/C/main01.c

CMakeFiles/main02.dir/main01.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main02.dir/main01.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lkit/Programming/C/main01.c > CMakeFiles/main02.dir/main01.c.i

CMakeFiles/main02.dir/main01.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main02.dir/main01.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lkit/Programming/C/main01.c -o CMakeFiles/main02.dir/main01.c.s

CMakeFiles/main02.dir/main01.c.o.requires:

.PHONY : CMakeFiles/main02.dir/main01.c.o.requires

CMakeFiles/main02.dir/main01.c.o.provides: CMakeFiles/main02.dir/main01.c.o.requires
	$(MAKE) -f CMakeFiles/main02.dir/build.make CMakeFiles/main02.dir/main01.c.o.provides.build
.PHONY : CMakeFiles/main02.dir/main01.c.o.provides

CMakeFiles/main02.dir/main01.c.o.provides.build: CMakeFiles/main02.dir/main01.c.o


CMakeFiles/main02.dir/main02.c.o: CMakeFiles/main02.dir/flags.make
CMakeFiles/main02.dir/main02.c.o: ../main02.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lkit/Programming/C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main02.dir/main02.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main02.dir/main02.c.o   -c /home/lkit/Programming/C/main02.c

CMakeFiles/main02.dir/main02.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main02.dir/main02.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lkit/Programming/C/main02.c > CMakeFiles/main02.dir/main02.c.i

CMakeFiles/main02.dir/main02.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main02.dir/main02.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lkit/Programming/C/main02.c -o CMakeFiles/main02.dir/main02.c.s

CMakeFiles/main02.dir/main02.c.o.requires:

.PHONY : CMakeFiles/main02.dir/main02.c.o.requires

CMakeFiles/main02.dir/main02.c.o.provides: CMakeFiles/main02.dir/main02.c.o.requires
	$(MAKE) -f CMakeFiles/main02.dir/build.make CMakeFiles/main02.dir/main02.c.o.provides.build
.PHONY : CMakeFiles/main02.dir/main02.c.o.provides

CMakeFiles/main02.dir/main02.c.o.provides.build: CMakeFiles/main02.dir/main02.c.o


# Object files for target main02
main02_OBJECTS = \
"CMakeFiles/main02.dir/main01.c.o" \
"CMakeFiles/main02.dir/main02.c.o"

# External object files for target main02
main02_EXTERNAL_OBJECTS =

main02: CMakeFiles/main02.dir/main01.c.o
main02: CMakeFiles/main02.dir/main02.c.o
main02: CMakeFiles/main02.dir/build.make
main02: CMakeFiles/main02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lkit/Programming/C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable main02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main02.dir/build: main02

.PHONY : CMakeFiles/main02.dir/build

CMakeFiles/main02.dir/requires: CMakeFiles/main02.dir/main01.c.o.requires
CMakeFiles/main02.dir/requires: CMakeFiles/main02.dir/main02.c.o.requires

.PHONY : CMakeFiles/main02.dir/requires

CMakeFiles/main02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main02.dir/clean

CMakeFiles/main02.dir/depend:
	cd /home/lkit/Programming/C/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lkit/Programming/C /home/lkit/Programming/C /home/lkit/Programming/C/build /home/lkit/Programming/C/build /home/lkit/Programming/C/build/CMakeFiles/main02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main02.dir/depend

