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
CMAKE_SOURCE_DIR = /home/vlad/CLionProjects/problems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/CLionProjects/problems/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problems.dir/flags.make

CMakeFiles/problems.dir/main.cpp.o: CMakeFiles/problems.dir/flags.make
CMakeFiles/problems.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/problems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problems.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problems.dir/main.cpp.o -c /home/vlad/CLionProjects/problems/main.cpp

CMakeFiles/problems.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problems.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/CLionProjects/problems/main.cpp > CMakeFiles/problems.dir/main.cpp.i

CMakeFiles/problems.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problems.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/CLionProjects/problems/main.cpp -o CMakeFiles/problems.dir/main.cpp.s

CMakeFiles/problems.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/problems.dir/main.cpp.o.requires

CMakeFiles/problems.dir/main.cpp.o.provides: CMakeFiles/problems.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/problems.dir/build.make CMakeFiles/problems.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/problems.dir/main.cpp.o.provides

CMakeFiles/problems.dir/main.cpp.o.provides.build: CMakeFiles/problems.dir/main.cpp.o


CMakeFiles/problems.dir/BSTree.cpp.o: CMakeFiles/problems.dir/flags.make
CMakeFiles/problems.dir/BSTree.cpp.o: ../BSTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/CLionProjects/problems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/problems.dir/BSTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/problems.dir/BSTree.cpp.o -c /home/vlad/CLionProjects/problems/BSTree.cpp

CMakeFiles/problems.dir/BSTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problems.dir/BSTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/CLionProjects/problems/BSTree.cpp > CMakeFiles/problems.dir/BSTree.cpp.i

CMakeFiles/problems.dir/BSTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problems.dir/BSTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/CLionProjects/problems/BSTree.cpp -o CMakeFiles/problems.dir/BSTree.cpp.s

CMakeFiles/problems.dir/BSTree.cpp.o.requires:

.PHONY : CMakeFiles/problems.dir/BSTree.cpp.o.requires

CMakeFiles/problems.dir/BSTree.cpp.o.provides: CMakeFiles/problems.dir/BSTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/problems.dir/build.make CMakeFiles/problems.dir/BSTree.cpp.o.provides.build
.PHONY : CMakeFiles/problems.dir/BSTree.cpp.o.provides

CMakeFiles/problems.dir/BSTree.cpp.o.provides.build: CMakeFiles/problems.dir/BSTree.cpp.o


# Object files for target problems
problems_OBJECTS = \
"CMakeFiles/problems.dir/main.cpp.o" \
"CMakeFiles/problems.dir/BSTree.cpp.o"

# External object files for target problems
problems_EXTERNAL_OBJECTS =

problems: CMakeFiles/problems.dir/main.cpp.o
problems: CMakeFiles/problems.dir/BSTree.cpp.o
problems: CMakeFiles/problems.dir/build.make
problems: CMakeFiles/problems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/CLionProjects/problems/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable problems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/problems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problems.dir/build: problems

.PHONY : CMakeFiles/problems.dir/build

CMakeFiles/problems.dir/requires: CMakeFiles/problems.dir/main.cpp.o.requires
CMakeFiles/problems.dir/requires: CMakeFiles/problems.dir/BSTree.cpp.o.requires

.PHONY : CMakeFiles/problems.dir/requires

CMakeFiles/problems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/problems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/problems.dir/clean

CMakeFiles/problems.dir/depend:
	cd /home/vlad/CLionProjects/problems/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/CLionProjects/problems /home/vlad/CLionProjects/problems /home/vlad/CLionProjects/problems/cmake-build-debug /home/vlad/CLionProjects/problems/cmake-build-debug /home/vlad/CLionProjects/problems/cmake-build-debug/CMakeFiles/problems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problems.dir/depend

