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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = J:/OneDrive/Projects/Game_Development/Watty/Demos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web

# Include any dependencies generated for this target.
include PlatformerDemo/CMakeFiles/PlatformerDemo.dir/depend.make

# Include the progress variables for this target.
include PlatformerDemo/CMakeFiles/PlatformerDemo.dir/progress.make

# Include the compile flags for this target's objects.
include PlatformerDemo/CMakeFiles/PlatformerDemo.dir/flags.make

PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.o: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/flags.make
PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.o: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/includes_CXX.rsp
PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.o: ../PlatformerDemo/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.o"
	cd J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo && J:/OneDrive/Projects/Game_Development/Watty/dependencies/emscripten/upstream/emscripten/em++.bat  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlatformerDemo.dir/src/main.cpp.o -c J:/OneDrive/Projects/Game_Development/Watty/Demos/PlatformerDemo/src/main.cpp

PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlatformerDemo.dir/src/main.cpp.i"
	cd J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo && J:/OneDrive/Projects/Game_Development/Watty/dependencies/emscripten/upstream/emscripten/em++.bat $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E J:/OneDrive/Projects/Game_Development/Watty/Demos/PlatformerDemo/src/main.cpp > CMakeFiles/PlatformerDemo.dir/src/main.cpp.i

PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlatformerDemo.dir/src/main.cpp.s"
	cd J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo && J:/OneDrive/Projects/Game_Development/Watty/dependencies/emscripten/upstream/emscripten/em++.bat $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S J:/OneDrive/Projects/Game_Development/Watty/Demos/PlatformerDemo/src/main.cpp -o CMakeFiles/PlatformerDemo.dir/src/main.cpp.s

# Object files for target PlatformerDemo
PlatformerDemo_OBJECTS = \
"CMakeFiles/PlatformerDemo.dir/src/main.cpp.o"

# External object files for target PlatformerDemo
PlatformerDemo_EXTERNAL_OBJECTS =

../bin/Web/PlatformerDemo.js: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/src/main.cpp.o
../bin/Web/PlatformerDemo.js: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/build.make
../bin/Web/PlatformerDemo.js: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/linklibs.rsp
../bin/Web/PlatformerDemo.js: PlatformerDemo/CMakeFiles/PlatformerDemo.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Web/PlatformerDemo.js"
	cd J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo && J:/OneDrive/Projects/Game_Development/Watty/dependencies/emscripten/upstream/emscripten/em++.bat   -std=c++17 -s MIN_WEBGL_VERSION=2 -s MAX_WEBGL_VERSION=2 -s WARN_UNALIGNED=1 -s ENVIRONMENT=web -s LLD_REPORT_UNDEFINED -s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1 -s ALLOW_MEMORY_GROWTH=1 -s DISABLE_EXCEPTION_CATCHING=2 --embed-file J:/OneDrive/Projects/Game_Development/Watty/Demos/res --embed-file J:/OneDrive/Projects/Game_Development/Watty/Demos/../Watty-Core//res --no-heap-copy   @CMakeFiles/PlatformerDemo.dir/objects1.rsp  -o ../../bin/Web/PlatformerDemo.js @CMakeFiles/PlatformerDemo.dir/linklibs.rsp

# Rule to build all files generated by this target.
PlatformerDemo/CMakeFiles/PlatformerDemo.dir/build: ../bin/Web/PlatformerDemo.js

.PHONY : PlatformerDemo/CMakeFiles/PlatformerDemo.dir/build

PlatformerDemo/CMakeFiles/PlatformerDemo.dir/clean:
	cd J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo && $(CMAKE_COMMAND) -P CMakeFiles/PlatformerDemo.dir/cmake_clean.cmake
.PHONY : PlatformerDemo/CMakeFiles/PlatformerDemo.dir/clean

PlatformerDemo/CMakeFiles/PlatformerDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" J:/OneDrive/Projects/Game_Development/Watty/Demos J:/OneDrive/Projects/Game_Development/Watty/Demos/PlatformerDemo J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo J:/OneDrive/Projects/Game_Development/Watty/Demos/build_web/PlatformerDemo/CMakeFiles/PlatformerDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PlatformerDemo/CMakeFiles/PlatformerDemo.dir/depend

