# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/pqb/huffman_codec_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pqb/huffman_codec_project/build

# Include any dependencies generated for this target.
include CMakeFiles/huffman_codec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman_codec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman_codec.dir/flags.make

CMakeFiles/huffman_codec.dir/main.cpp.o: CMakeFiles/huffman_codec.dir/flags.make
CMakeFiles/huffman_codec.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman_codec.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman_codec.dir/main.cpp.o -c /home/pqb/huffman_codec_project/main.cpp

CMakeFiles/huffman_codec.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_codec.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pqb/huffman_codec_project/main.cpp > CMakeFiles/huffman_codec.dir/main.cpp.i

CMakeFiles/huffman_codec.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_codec.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pqb/huffman_codec_project/main.cpp -o CMakeFiles/huffman_codec.dir/main.cpp.s

CMakeFiles/huffman_codec.dir/src/compressor.cpp.o: CMakeFiles/huffman_codec.dir/flags.make
CMakeFiles/huffman_codec.dir/src/compressor.cpp.o: ../src/compressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/huffman_codec.dir/src/compressor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman_codec.dir/src/compressor.cpp.o -c /home/pqb/huffman_codec_project/src/compressor.cpp

CMakeFiles/huffman_codec.dir/src/compressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_codec.dir/src/compressor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pqb/huffman_codec_project/src/compressor.cpp > CMakeFiles/huffman_codec.dir/src/compressor.cpp.i

CMakeFiles/huffman_codec.dir/src/compressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_codec.dir/src/compressor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pqb/huffman_codec_project/src/compressor.cpp -o CMakeFiles/huffman_codec.dir/src/compressor.cpp.s

CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o: CMakeFiles/huffman_codec.dir/flags.make
CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o: ../src/decompressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o -c /home/pqb/huffman_codec_project/src/decompressor.cpp

CMakeFiles/huffman_codec.dir/src/decompressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_codec.dir/src/decompressor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pqb/huffman_codec_project/src/decompressor.cpp > CMakeFiles/huffman_codec.dir/src/decompressor.cpp.i

CMakeFiles/huffman_codec.dir/src/decompressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_codec.dir/src/decompressor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pqb/huffman_codec_project/src/decompressor.cpp -o CMakeFiles/huffman_codec.dir/src/decompressor.cpp.s

CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o: CMakeFiles/huffman_codec.dir/flags.make
CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o: ../src/huffman_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o -c /home/pqb/huffman_codec_project/src/huffman_tree.cpp

CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pqb/huffman_codec_project/src/huffman_tree.cpp > CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.i

CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pqb/huffman_codec_project/src/huffman_tree.cpp -o CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.s

CMakeFiles/huffman_codec.dir/src/utils.cpp.o: CMakeFiles/huffman_codec.dir/flags.make
CMakeFiles/huffman_codec.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/huffman_codec.dir/src/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman_codec.dir/src/utils.cpp.o -c /home/pqb/huffman_codec_project/src/utils.cpp

CMakeFiles/huffman_codec.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_codec.dir/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pqb/huffman_codec_project/src/utils.cpp > CMakeFiles/huffman_codec.dir/src/utils.cpp.i

CMakeFiles/huffman_codec.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_codec.dir/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pqb/huffman_codec_project/src/utils.cpp -o CMakeFiles/huffman_codec.dir/src/utils.cpp.s

# Object files for target huffman_codec
huffman_codec_OBJECTS = \
"CMakeFiles/huffman_codec.dir/main.cpp.o" \
"CMakeFiles/huffman_codec.dir/src/compressor.cpp.o" \
"CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o" \
"CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o" \
"CMakeFiles/huffman_codec.dir/src/utils.cpp.o"

# External object files for target huffman_codec
huffman_codec_EXTERNAL_OBJECTS =

huffman_codec: CMakeFiles/huffman_codec.dir/main.cpp.o
huffman_codec: CMakeFiles/huffman_codec.dir/src/compressor.cpp.o
huffman_codec: CMakeFiles/huffman_codec.dir/src/decompressor.cpp.o
huffman_codec: CMakeFiles/huffman_codec.dir/src/huffman_tree.cpp.o
huffman_codec: CMakeFiles/huffman_codec.dir/src/utils.cpp.o
huffman_codec: CMakeFiles/huffman_codec.dir/build.make
huffman_codec: CMakeFiles/huffman_codec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pqb/huffman_codec_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable huffman_codec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman_codec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman_codec.dir/build: huffman_codec

.PHONY : CMakeFiles/huffman_codec.dir/build

CMakeFiles/huffman_codec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman_codec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman_codec.dir/clean

CMakeFiles/huffman_codec.dir/depend:
	cd /home/pqb/huffman_codec_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pqb/huffman_codec_project /home/pqb/huffman_codec_project /home/pqb/huffman_codec_project/build /home/pqb/huffman_codec_project/build /home/pqb/huffman_codec_project/build/CMakeFiles/huffman_codec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huffman_codec.dir/depend

