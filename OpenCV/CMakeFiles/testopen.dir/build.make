# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/julio/OpenCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julio/OpenCV

# Include any dependencies generated for this target.
include CMakeFiles/testopen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testopen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testopen.dir/flags.make

CMakeFiles/testopen.dir/testopen.cpp.o: CMakeFiles/testopen.dir/flags.make
CMakeFiles/testopen.dir/testopen.cpp.o: testopen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julio/OpenCV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testopen.dir/testopen.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testopen.dir/testopen.cpp.o -c /home/julio/OpenCV/testopen.cpp

CMakeFiles/testopen.dir/testopen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopen.dir/testopen.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julio/OpenCV/testopen.cpp > CMakeFiles/testopen.dir/testopen.cpp.i

CMakeFiles/testopen.dir/testopen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopen.dir/testopen.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julio/OpenCV/testopen.cpp -o CMakeFiles/testopen.dir/testopen.cpp.s

CMakeFiles/testopen.dir/testopen.cpp.o.requires:

.PHONY : CMakeFiles/testopen.dir/testopen.cpp.o.requires

CMakeFiles/testopen.dir/testopen.cpp.o.provides: CMakeFiles/testopen.dir/testopen.cpp.o.requires
	$(MAKE) -f CMakeFiles/testopen.dir/build.make CMakeFiles/testopen.dir/testopen.cpp.o.provides.build
.PHONY : CMakeFiles/testopen.dir/testopen.cpp.o.provides

CMakeFiles/testopen.dir/testopen.cpp.o.provides.build: CMakeFiles/testopen.dir/testopen.cpp.o


# Object files for target testopen
testopen_OBJECTS = \
"CMakeFiles/testopen.dir/testopen.cpp.o"

# External object files for target testopen
testopen_EXTERNAL_OBJECTS =

testopen: CMakeFiles/testopen.dir/testopen.cpp.o
testopen: CMakeFiles/testopen.dir/build.make
testopen: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
testopen: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
testopen: CMakeFiles/testopen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julio/OpenCV/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testopen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testopen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testopen.dir/build: testopen

.PHONY : CMakeFiles/testopen.dir/build

CMakeFiles/testopen.dir/requires: CMakeFiles/testopen.dir/testopen.cpp.o.requires

.PHONY : CMakeFiles/testopen.dir/requires

CMakeFiles/testopen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testopen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testopen.dir/clean

CMakeFiles/testopen.dir/depend:
	cd /home/julio/OpenCV && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julio/OpenCV /home/julio/OpenCV /home/julio/OpenCV /home/julio/OpenCV /home/julio/OpenCV/CMakeFiles/testopen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testopen.dir/depend

