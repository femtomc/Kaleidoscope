# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mccoybecker/Dev/Kaleidoscope

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mccoybecker/Dev/Kaleidoscope/build

# Include any dependencies generated for this target.
include CMakeFiles/Kaleidoscope.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Kaleidoscope.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kaleidoscope.dir/flags.make

CMakeFiles/Kaleidoscope.dir/src/main.cpp.o: CMakeFiles/Kaleidoscope.dir/flags.make
CMakeFiles/Kaleidoscope.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mccoybecker/Dev/Kaleidoscope/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kaleidoscope.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Kaleidoscope.dir/src/main.cpp.o -c /Users/mccoybecker/Dev/Kaleidoscope/src/main.cpp

CMakeFiles/Kaleidoscope.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kaleidoscope.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mccoybecker/Dev/Kaleidoscope/src/main.cpp > CMakeFiles/Kaleidoscope.dir/src/main.cpp.i

CMakeFiles/Kaleidoscope.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kaleidoscope.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mccoybecker/Dev/Kaleidoscope/src/main.cpp -o CMakeFiles/Kaleidoscope.dir/src/main.cpp.s

# Object files for target Kaleidoscope
Kaleidoscope_OBJECTS = \
"CMakeFiles/Kaleidoscope.dir/src/main.cpp.o"

# External object files for target Kaleidoscope
Kaleidoscope_EXTERNAL_OBJECTS =

Kaleidoscope: CMakeFiles/Kaleidoscope.dir/src/main.cpp.o
Kaleidoscope: CMakeFiles/Kaleidoscope.dir/build.make
Kaleidoscope: lib/liblib.a
Kaleidoscope: CMakeFiles/Kaleidoscope.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mccoybecker/Dev/Kaleidoscope/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Kaleidoscope"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Kaleidoscope.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kaleidoscope.dir/build: Kaleidoscope

.PHONY : CMakeFiles/Kaleidoscope.dir/build

CMakeFiles/Kaleidoscope.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Kaleidoscope.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Kaleidoscope.dir/clean

CMakeFiles/Kaleidoscope.dir/depend:
	cd /Users/mccoybecker/Dev/Kaleidoscope/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mccoybecker/Dev/Kaleidoscope /Users/mccoybecker/Dev/Kaleidoscope /Users/mccoybecker/Dev/Kaleidoscope/build /Users/mccoybecker/Dev/Kaleidoscope/build /Users/mccoybecker/Dev/Kaleidoscope/build/CMakeFiles/Kaleidoscope.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kaleidoscope.dir/depend

