# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projekt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projekt.dir/flags.make

CMakeFiles/Projekt.dir/Directory/main.cpp.o: CMakeFiles/Projekt.dir/flags.make
CMakeFiles/Projekt.dir/Directory/main.cpp.o: ../Directory/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projekt.dir/Directory/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projekt.dir/Directory/main.cpp.o -c /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/main.cpp

CMakeFiles/Projekt.dir/Directory/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projekt.dir/Directory/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/main.cpp > CMakeFiles/Projekt.dir/Directory/main.cpp.i

CMakeFiles/Projekt.dir/Directory/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projekt.dir/Directory/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/Directory/main.cpp -o CMakeFiles/Projekt.dir/Directory/main.cpp.s

# Object files for target Projekt
Projekt_OBJECTS = \
"CMakeFiles/Projekt.dir/Directory/main.cpp.o"

# External object files for target Projekt
Projekt_EXTERNAL_OBJECTS =

Projekt: CMakeFiles/Projekt.dir/Directory/main.cpp.o
Projekt: CMakeFiles/Projekt.dir/build.make
Projekt: CMakeFiles/Projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Projekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projekt.dir/build: Projekt

.PHONY : CMakeFiles/Projekt.dir/build

CMakeFiles/Projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projekt.dir/clean

CMakeFiles/Projekt.dir/depend:
	cd /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug /Users/Dynia/Desktop/Studia/PJATK/PJC/Projekt/cmake-build-debug/CMakeFiles/Projekt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projekt.dir/depend

