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
CMAKE_SOURCE_DIR = /home/vlad/CLionProjects/problem24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/CLionProjects/problem24/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problem24.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem24.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem24.dir/flags.make

CMakeFiles/problem24.dir/main.cpp.o: CMakeFiles/problem24.dir/flags.make
CMakeFiles/problem24.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/problem24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem24.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem24.dir/main.cpp.o -c /home/vlad/CLionProjects/problem24/main.cpp

CMakeFiles/problem24.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem24.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/CLionProjects/problem24/main.cpp > CMakeFiles/problem24.dir/main.cpp.i

CMakeFiles/problem24.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem24.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/CLionProjects/problem24/main.cpp -o CMakeFiles/problem24.dir/main.cpp.s

CMakeFiles/problem24.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/problem24.dir/main.cpp.o.requires

CMakeFiles/problem24.dir/main.cpp.o.provides: CMakeFiles/problem24.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/problem24.dir/build.make CMakeFiles/problem24.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/problem24.dir/main.cpp.o.provides

CMakeFiles/problem24.dir/main.cpp.o.provides.build: CMakeFiles/problem24.dir/main.cpp.o


CMakeFiles/problem24.dir/ConsHashRing.cpp.o: CMakeFiles/problem24.dir/flags.make
CMakeFiles/problem24.dir/ConsHashRing.cpp.o: ../ConsHashRing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/problem24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/problem24.dir/ConsHashRing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problem24.dir/ConsHashRing.cpp.o -c /home/vlad/CLionProjects/problem24/ConsHashRing.cpp

CMakeFiles/problem24.dir/ConsHashRing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem24.dir/ConsHashRing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/CLionProjects/problem24/ConsHashRing.cpp > CMakeFiles/problem24.dir/ConsHashRing.cpp.i

CMakeFiles/problem24.dir/ConsHashRing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem24.dir/ConsHashRing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/CLionProjects/problem24/ConsHashRing.cpp -o CMakeFiles/problem24.dir/ConsHashRing.cpp.s

CMakeFiles/problem24.dir/ConsHashRing.cpp.o.requires:

.PHONY : CMakeFiles/problem24.dir/ConsHashRing.cpp.o.requires

CMakeFiles/problem24.dir/ConsHashRing.cpp.o.provides: CMakeFiles/problem24.dir/ConsHashRing.cpp.o.requires
	$(MAKE) -f CMakeFiles/problem24.dir/build.make CMakeFiles/problem24.dir/ConsHashRing.cpp.o.provides.build
.PHONY : CMakeFiles/problem24.dir/ConsHashRing.cpp.o.provides

CMakeFiles/problem24.dir/ConsHashRing.cpp.o.provides.build: CMakeFiles/problem24.dir/ConsHashRing.cpp.o


# Object files for target problem24
problem24_OBJECTS = \
"CMakeFiles/problem24.dir/main.cpp.o" \
"CMakeFiles/problem24.dir/ConsHashRing.cpp.o"

# External object files for target problem24
problem24_EXTERNAL_OBJECTS =

problem24: CMakeFiles/problem24.dir/main.cpp.o
problem24: CMakeFiles/problem24.dir/ConsHashRing.cpp.o
problem24: CMakeFiles/problem24.dir/build.make
problem24: CMakeFiles/problem24.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/CLionProjects/problem24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable problem24"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problem24.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem24.dir/build: problem24

.PHONY : CMakeFiles/problem24.dir/build

CMakeFiles/problem24.dir/requires: CMakeFiles/problem24.dir/main.cpp.o.requires
CMakeFiles/problem24.dir/requires: CMakeFiles/problem24.dir/ConsHashRing.cpp.o.requires

.PHONY : CMakeFiles/problem24.dir/requires

CMakeFiles/problem24.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problem24.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problem24.dir/clean

CMakeFiles/problem24.dir/depend:
	cd /home/vlad/CLionProjects/problem24/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/CLionProjects/problem24 /home/vlad/CLionProjects/problem24 /home/vlad/CLionProjects/problem24/cmake-build-debug /home/vlad/CLionProjects/problem24/cmake-build-debug /home/vlad/CLionProjects/problem24/cmake-build-debug/CMakeFiles/problem24.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problem24.dir/depend

