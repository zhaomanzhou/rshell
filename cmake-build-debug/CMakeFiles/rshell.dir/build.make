# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/clion-2018.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/local/clion-2018.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zmz/CLionProjects/rshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zmz/CLionProjects/rshell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rshell.dir/flags.make

CMakeFiles/rshell.dir/src/main.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rshell.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/main.cpp.o -c /home/zmz/CLionProjects/rshell/src/main.cpp

CMakeFiles/rshell.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zmz/CLionProjects/rshell/src/main.cpp > CMakeFiles/rshell.dir/src/main.cpp.i

CMakeFiles/rshell.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zmz/CLionProjects/rshell/src/main.cpp -o CMakeFiles/rshell.dir/src/main.cpp.s

CMakeFiles/rshell.dir/src/Command.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/Command.cpp.o: ../src/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rshell.dir/src/Command.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/Command.cpp.o -c /home/zmz/CLionProjects/rshell/src/Command.cpp

CMakeFiles/rshell.dir/src/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zmz/CLionProjects/rshell/src/Command.cpp > CMakeFiles/rshell.dir/src/Command.cpp.i

CMakeFiles/rshell.dir/src/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zmz/CLionProjects/rshell/src/Command.cpp -o CMakeFiles/rshell.dir/src/Command.cpp.s

CMakeFiles/rshell.dir/src/Lexical.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/Lexical.cpp.o: ../src/Lexical.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rshell.dir/src/Lexical.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/Lexical.cpp.o -c /home/zmz/CLionProjects/rshell/src/Lexical.cpp

CMakeFiles/rshell.dir/src/Lexical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/Lexical.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zmz/CLionProjects/rshell/src/Lexical.cpp > CMakeFiles/rshell.dir/src/Lexical.cpp.i

CMakeFiles/rshell.dir/src/Lexical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/Lexical.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zmz/CLionProjects/rshell/src/Lexical.cpp -o CMakeFiles/rshell.dir/src/Lexical.cpp.s

CMakeFiles/rshell.dir/src/Connector.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/Connector.cpp.o: ../src/Connector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rshell.dir/src/Connector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/Connector.cpp.o -c /home/zmz/CLionProjects/rshell/src/Connector.cpp

CMakeFiles/rshell.dir/src/Connector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/Connector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zmz/CLionProjects/rshell/src/Connector.cpp > CMakeFiles/rshell.dir/src/Connector.cpp.i

CMakeFiles/rshell.dir/src/Connector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/Connector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zmz/CLionProjects/rshell/src/Connector.cpp -o CMakeFiles/rshell.dir/src/Connector.cpp.s

# Object files for target rshell
rshell_OBJECTS = \
"CMakeFiles/rshell.dir/src/main.cpp.o" \
"CMakeFiles/rshell.dir/src/Command.cpp.o" \
"CMakeFiles/rshell.dir/src/Lexical.cpp.o" \
"CMakeFiles/rshell.dir/src/Connector.cpp.o"

# External object files for target rshell
rshell_EXTERNAL_OBJECTS =

rshell: CMakeFiles/rshell.dir/src/main.cpp.o
rshell: CMakeFiles/rshell.dir/src/Command.cpp.o
rshell: CMakeFiles/rshell.dir/src/Lexical.cpp.o
rshell: CMakeFiles/rshell.dir/src/Connector.cpp.o
rshell: CMakeFiles/rshell.dir/build.make
rshell: CMakeFiles/rshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable rshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rshell.dir/build: rshell

.PHONY : CMakeFiles/rshell.dir/build

CMakeFiles/rshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rshell.dir/clean

CMakeFiles/rshell.dir/depend:
	cd /home/zmz/CLionProjects/rshell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zmz/CLionProjects/rshell /home/zmz/CLionProjects/rshell /home/zmz/CLionProjects/rshell/cmake-build-debug /home/zmz/CLionProjects/rshell/cmake-build-debug /home/zmz/CLionProjects/rshell/cmake-build-debug/CMakeFiles/rshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rshell.dir/depend
