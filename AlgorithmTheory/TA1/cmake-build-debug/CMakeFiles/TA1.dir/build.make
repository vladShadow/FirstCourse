# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vlad/CLionProjects/TA1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/CLionProjects/TA1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TA1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TA1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TA1.dir/flags.make

CMakeFiles/TA1.dir/main.cpp.o: CMakeFiles/TA1.dir/flags.make
CMakeFiles/TA1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/TA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TA1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TA1.dir/main.cpp.o -c /home/vlad/CLionProjects/TA1/main.cpp

CMakeFiles/TA1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TA1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/CLionProjects/TA1/main.cpp > CMakeFiles/TA1.dir/main.cpp.i

CMakeFiles/TA1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TA1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/CLionProjects/TA1/main.cpp -o CMakeFiles/TA1.dir/main.cpp.s

CMakeFiles/TA1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TA1.dir/main.cpp.o.requires

CMakeFiles/TA1.dir/main.cpp.o.provides: CMakeFiles/TA1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TA1.dir/build.make CMakeFiles/TA1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TA1.dir/main.cpp.o.provides

CMakeFiles/TA1.dir/main.cpp.o.provides.build: CMakeFiles/TA1.dir/main.cpp.o


# Object files for target TA1
TA1_OBJECTS = \
"CMakeFiles/TA1.dir/main.cpp.o"

# External object files for target TA1
TA1_EXTERNAL_OBJECTS =

TA1: CMakeFiles/TA1.dir/main.cpp.o
TA1: CMakeFiles/TA1.dir/build.make
TA1: CMakeFiles/TA1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/CLionProjects/TA1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TA1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TA1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TA1.dir/build: TA1

.PHONY : CMakeFiles/TA1.dir/build

CMakeFiles/TA1.dir/requires: CMakeFiles/TA1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/TA1.dir/requires

CMakeFiles/TA1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TA1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TA1.dir/clean

CMakeFiles/TA1.dir/depend:
	cd /home/vlad/CLionProjects/TA1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/CLionProjects/TA1 /home/vlad/CLionProjects/TA1 /home/vlad/CLionProjects/TA1/cmake-build-debug /home/vlad/CLionProjects/TA1/cmake-build-debug /home/vlad/CLionProjects/TA1/cmake-build-debug/CMakeFiles/TA1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TA1.dir/depend
