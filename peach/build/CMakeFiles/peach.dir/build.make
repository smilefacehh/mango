# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/cmake-3.20.0/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.20.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/narwal/workspace/me/mango/peach

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/narwal/workspace/me/mango/peach/build

# Include any dependencies generated for this target.
include CMakeFiles/peach.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/peach.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/peach.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/peach.dir/flags.make

CMakeFiles/peach.dir/mono.cpp.o: CMakeFiles/peach.dir/flags.make
CMakeFiles/peach.dir/mono.cpp.o: ../mono.cpp
CMakeFiles/peach.dir/mono.cpp.o: CMakeFiles/peach.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/narwal/workspace/me/mango/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/peach.dir/mono.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/peach.dir/mono.cpp.o -MF CMakeFiles/peach.dir/mono.cpp.o.d -o CMakeFiles/peach.dir/mono.cpp.o -c /home/narwal/workspace/me/mango/peach/mono.cpp

CMakeFiles/peach.dir/mono.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/peach.dir/mono.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/narwal/workspace/me/mango/peach/mono.cpp > CMakeFiles/peach.dir/mono.cpp.i

CMakeFiles/peach.dir/mono.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/peach.dir/mono.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/narwal/workspace/me/mango/peach/mono.cpp -o CMakeFiles/peach.dir/mono.cpp.s

# Object files for target peach
peach_OBJECTS = \
"CMakeFiles/peach.dir/mono.cpp.o"

# External object files for target peach
peach_EXTERNAL_OBJECTS =

peach: CMakeFiles/peach.dir/mono.cpp.o
peach: CMakeFiles/peach.dir/build.make
peach: libpeach_lib.a
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_stitching3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_superres3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_videostab3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_aruco3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_bgsegm3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_bioinspired3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ccalib3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_cvv3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_dpm3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_face3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_photo3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_fuzzy3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_hdf3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_img_hash3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_line_descriptor3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_optflow3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_reg3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_rgbd3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_saliency3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_stereo3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_structured_light3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_viz3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_phase_unwrapping3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_surface_matching3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_tracking3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_datasets3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_plot3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_text3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_dnn3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xfeatures2d3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ml3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_shape3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_video3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ximgproc3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_calib3d3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_features2d3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_flann3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_highgui3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_videoio3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xobjdetect3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_objdetect3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xphoto3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
peach: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
peach: CMakeFiles/peach.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/narwal/workspace/me/mango/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable peach"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/peach.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/peach.dir/build: peach
.PHONY : CMakeFiles/peach.dir/build

CMakeFiles/peach.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/peach.dir/cmake_clean.cmake
.PHONY : CMakeFiles/peach.dir/clean

CMakeFiles/peach.dir/depend:
	cd /home/narwal/workspace/me/mango/peach/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/narwal/workspace/me/mango/peach /home/narwal/workspace/me/mango/peach /home/narwal/workspace/me/mango/peach/build /home/narwal/workspace/me/mango/peach/build /home/narwal/workspace/me/mango/peach/build/CMakeFiles/peach.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/peach.dir/depend

