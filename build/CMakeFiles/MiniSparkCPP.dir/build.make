# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kanishk/Downloads/Big-Data/MiniSparkCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kanishk/Downloads/Big-Data/MiniSparkCPP/build

# Include any dependencies generated for this target.
include CMakeFiles/MiniSparkCPP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MiniSparkCPP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MiniSparkCPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiniSparkCPP.dir/flags.make

CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o: CMakeFiles/MiniSparkCPP.dir/flags.make
CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o: ../src/FileRDD.cpp
CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o: CMakeFiles/MiniSparkCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o -MF CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o.d -o CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o -c /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/FileRDD.cpp

CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/FileRDD.cpp > CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.i

CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/FileRDD.cpp -o CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.s

CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o: CMakeFiles/MiniSparkCPP.dir/flags.make
CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o: ../src/LogisticRegression.cpp
CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o: CMakeFiles/MiniSparkCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o -MF CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o.d -o CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o -c /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/LogisticRegression.cpp

CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/LogisticRegression.cpp > CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.i

CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/LogisticRegression.cpp -o CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.s

CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o: CMakeFiles/MiniSparkCPP.dir/flags.make
CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o: ../src/MiniSparkApp.cpp
CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o: CMakeFiles/MiniSparkCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o -MF CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o.d -o CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o -c /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/MiniSparkApp.cpp

CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/MiniSparkApp.cpp > CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.i

CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/MiniSparkApp.cpp -o CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.s

CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o: CMakeFiles/MiniSparkCPP.dir/flags.make
CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o: ../src/PageRank.cpp
CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o: CMakeFiles/MiniSparkCPP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o -MF CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o.d -o CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o -c /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/PageRank.cpp

CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/PageRank.cpp > CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.i

CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kanishk/Downloads/Big-Data/MiniSparkCPP/src/PageRank.cpp -o CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.s

# Object files for target MiniSparkCPP
MiniSparkCPP_OBJECTS = \
"CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o" \
"CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o" \
"CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o" \
"CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o"

# External object files for target MiniSparkCPP
MiniSparkCPP_EXTERNAL_OBJECTS =

MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/src/FileRDD.cpp.o
MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/src/LogisticRegression.cpp.o
MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/src/MiniSparkApp.cpp.o
MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/src/PageRank.cpp.o
MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/build.make
MiniSparkCPP: CMakeFiles/MiniSparkCPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MiniSparkCPP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiniSparkCPP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiniSparkCPP.dir/build: MiniSparkCPP
.PHONY : CMakeFiles/MiniSparkCPP.dir/build

CMakeFiles/MiniSparkCPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiniSparkCPP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiniSparkCPP.dir/clean

CMakeFiles/MiniSparkCPP.dir/depend:
	cd /home/kanishk/Downloads/Big-Data/MiniSparkCPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kanishk/Downloads/Big-Data/MiniSparkCPP /home/kanishk/Downloads/Big-Data/MiniSparkCPP /home/kanishk/Downloads/Big-Data/MiniSparkCPP/build /home/kanishk/Downloads/Big-Data/MiniSparkCPP/build /home/kanishk/Downloads/Big-Data/MiniSparkCPP/build/CMakeFiles/MiniSparkCPP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiniSparkCPP.dir/depend

