# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/o/okres/ClionProjects/PushSwap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PushSwap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PushSwap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PushSwap.dir/flags.make

CMakeFiles/PushSwap.dir/main.c.o: CMakeFiles/PushSwap.dir/flags.make
CMakeFiles/PushSwap.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PushSwap.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PushSwap.dir/main.c.o   -c /nfs/2016/o/okres/ClionProjects/PushSwap/main.c

CMakeFiles/PushSwap.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PushSwap.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/o/okres/ClionProjects/PushSwap/main.c > CMakeFiles/PushSwap.dir/main.c.i

CMakeFiles/PushSwap.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PushSwap.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/o/okres/ClionProjects/PushSwap/main.c -o CMakeFiles/PushSwap.dir/main.c.s

CMakeFiles/PushSwap.dir/main.c.o.requires:

.PHONY : CMakeFiles/PushSwap.dir/main.c.o.requires

CMakeFiles/PushSwap.dir/main.c.o.provides: CMakeFiles/PushSwap.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/PushSwap.dir/build.make CMakeFiles/PushSwap.dir/main.c.o.provides.build
.PHONY : CMakeFiles/PushSwap.dir/main.c.o.provides

CMakeFiles/PushSwap.dir/main.c.o.provides.build: CMakeFiles/PushSwap.dir/main.c.o


# Object files for target PushSwap
PushSwap_OBJECTS = \
"CMakeFiles/PushSwap.dir/main.c.o"

# External object files for target PushSwap
PushSwap_EXTERNAL_OBJECTS =

PushSwap: CMakeFiles/PushSwap.dir/main.c.o
PushSwap: CMakeFiles/PushSwap.dir/build.make
PushSwap: CMakeFiles/PushSwap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PushSwap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PushSwap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PushSwap.dir/build: PushSwap

.PHONY : CMakeFiles/PushSwap.dir/build

CMakeFiles/PushSwap.dir/requires: CMakeFiles/PushSwap.dir/main.c.o.requires

.PHONY : CMakeFiles/PushSwap.dir/requires

CMakeFiles/PushSwap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PushSwap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PushSwap.dir/clean

CMakeFiles/PushSwap.dir/depend:
	cd /nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/o/okres/ClionProjects/PushSwap /nfs/2016/o/okres/ClionProjects/PushSwap /nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug /nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug /nfs/2016/o/okres/ClionProjects/PushSwap/cmake-build-debug/CMakeFiles/PushSwap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PushSwap.dir/depend

