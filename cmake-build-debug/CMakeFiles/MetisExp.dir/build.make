# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/97/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/97/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vikrambhatt/CLionProjects/MetisExp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MetisExp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MetisExp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MetisExp.dir/flags.make

CMakeFiles/MetisExp.dir/adjtocsr.cpp.o: CMakeFiles/MetisExp.dir/flags.make
CMakeFiles/MetisExp.dir/adjtocsr.cpp.o: ../adjtocsr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MetisExp.dir/adjtocsr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetisExp.dir/adjtocsr.cpp.o -c /home/vikrambhatt/CLionProjects/MetisExp/adjtocsr.cpp

CMakeFiles/MetisExp.dir/adjtocsr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetisExp.dir/adjtocsr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/MetisExp/adjtocsr.cpp > CMakeFiles/MetisExp.dir/adjtocsr.cpp.i

CMakeFiles/MetisExp.dir/adjtocsr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetisExp.dir/adjtocsr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/MetisExp/adjtocsr.cpp -o CMakeFiles/MetisExp.dir/adjtocsr.cpp.s

CMakeFiles/MetisExp.dir/main.cpp.o: CMakeFiles/MetisExp.dir/flags.make
CMakeFiles/MetisExp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MetisExp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetisExp.dir/main.cpp.o -c /home/vikrambhatt/CLionProjects/MetisExp/main.cpp

CMakeFiles/MetisExp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetisExp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/MetisExp/main.cpp > CMakeFiles/MetisExp.dir/main.cpp.i

CMakeFiles/MetisExp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetisExp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/MetisExp/main.cpp -o CMakeFiles/MetisExp.dir/main.cpp.s

# Object files for target MetisExp
MetisExp_OBJECTS = \
"CMakeFiles/MetisExp.dir/adjtocsr.cpp.o" \
"CMakeFiles/MetisExp.dir/main.cpp.o"

# External object files for target MetisExp
MetisExp_EXTERNAL_OBJECTS =

MetisExp: CMakeFiles/MetisExp.dir/adjtocsr.cpp.o
MetisExp: CMakeFiles/MetisExp.dir/main.cpp.o
MetisExp: CMakeFiles/MetisExp.dir/build.make
MetisExp: /usr/local/lib/libmpi.so
MetisExp: CMakeFiles/MetisExp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MetisExp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MetisExp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MetisExp.dir/build: MetisExp

.PHONY : CMakeFiles/MetisExp.dir/build

CMakeFiles/MetisExp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MetisExp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MetisExp.dir/clean

CMakeFiles/MetisExp.dir/depend:
	cd /home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vikrambhatt/CLionProjects/MetisExp /home/vikrambhatt/CLionProjects/MetisExp /home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug /home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug /home/vikrambhatt/CLionProjects/MetisExp/cmake-build-debug/CMakeFiles/MetisExp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MetisExp.dir/depend
