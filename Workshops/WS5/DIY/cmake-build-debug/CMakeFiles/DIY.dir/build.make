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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DIY.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DIY.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DIY.dir/flags.make

CMakeFiles/DIY.dir/Mark.cpp.o: CMakeFiles/DIY.dir/flags.make
CMakeFiles/DIY.dir/Mark.cpp.o: ../Mark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DIY.dir/Mark.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DIY.dir/Mark.cpp.o -c "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/Mark.cpp"

CMakeFiles/DIY.dir/Mark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DIY.dir/Mark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/Mark.cpp" > CMakeFiles/DIY.dir/Mark.cpp.i

CMakeFiles/DIY.dir/Mark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DIY.dir/Mark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/Mark.cpp" -o CMakeFiles/DIY.dir/Mark.cpp.s

CMakeFiles/DIY.dir/markMain.cpp.o: CMakeFiles/DIY.dir/flags.make
CMakeFiles/DIY.dir/markMain.cpp.o: ../markMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DIY.dir/markMain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DIY.dir/markMain.cpp.o -c "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/markMain.cpp"

CMakeFiles/DIY.dir/markMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DIY.dir/markMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/markMain.cpp" > CMakeFiles/DIY.dir/markMain.cpp.i

CMakeFiles/DIY.dir/markMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DIY.dir/markMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/markMain.cpp" -o CMakeFiles/DIY.dir/markMain.cpp.s

# Object files for target DIY
DIY_OBJECTS = \
"CMakeFiles/DIY.dir/Mark.cpp.o" \
"CMakeFiles/DIY.dir/markMain.cpp.o"

# External object files for target DIY
DIY_EXTERNAL_OBJECTS =

DIY: CMakeFiles/DIY.dir/Mark.cpp.o
DIY: CMakeFiles/DIY.dir/markMain.cpp.o
DIY: CMakeFiles/DIY.dir/build.make
DIY: CMakeFiles/DIY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DIY"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DIY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DIY.dir/build: DIY

.PHONY : CMakeFiles/DIY.dir/build

CMakeFiles/DIY.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DIY.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DIY.dir/clean

CMakeFiles/DIY.dir/depend:
	cd "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY" "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY" "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug" "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug" "/home/john/Seneca/2nd Semester/OOP244 - Introduction to Objeect Oriented Programming/WS5/DIY/cmake-build-debug/CMakeFiles/DIY.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DIY.dir/depend

