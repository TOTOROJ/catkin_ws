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
CMAKE_SOURCE_DIR = /home/totoro/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/totoro/catkin_ws/build

# Include any dependencies generated for this target.
include auv/CMakeFiles/a.dir/depend.make

# Include the progress variables for this target.
include auv/CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include auv/CMakeFiles/a.dir/flags.make

auv/CMakeFiles/a.dir/src/a.cpp.o: auv/CMakeFiles/a.dir/flags.make
auv/CMakeFiles/a.dir/src/a.cpp.o: /home/totoro/catkin_ws/src/auv/src/a.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/totoro/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object auv/CMakeFiles/a.dir/src/a.cpp.o"
	cd /home/totoro/catkin_ws/build/auv && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.dir/src/a.cpp.o -c /home/totoro/catkin_ws/src/auv/src/a.cpp

auv/CMakeFiles/a.dir/src/a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.dir/src/a.cpp.i"
	cd /home/totoro/catkin_ws/build/auv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/totoro/catkin_ws/src/auv/src/a.cpp > CMakeFiles/a.dir/src/a.cpp.i

auv/CMakeFiles/a.dir/src/a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.dir/src/a.cpp.s"
	cd /home/totoro/catkin_ws/build/auv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/totoro/catkin_ws/src/auv/src/a.cpp -o CMakeFiles/a.dir/src/a.cpp.s

auv/CMakeFiles/a.dir/src/a.cpp.o.requires:

.PHONY : auv/CMakeFiles/a.dir/src/a.cpp.o.requires

auv/CMakeFiles/a.dir/src/a.cpp.o.provides: auv/CMakeFiles/a.dir/src/a.cpp.o.requires
	$(MAKE) -f auv/CMakeFiles/a.dir/build.make auv/CMakeFiles/a.dir/src/a.cpp.o.provides.build
.PHONY : auv/CMakeFiles/a.dir/src/a.cpp.o.provides

auv/CMakeFiles/a.dir/src/a.cpp.o.provides.build: auv/CMakeFiles/a.dir/src/a.cpp.o


# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/src/a.cpp.o"

# External object files for target a
a_EXTERNAL_OBJECTS =

/home/totoro/catkin_ws/devel/lib/liba.so: auv/CMakeFiles/a.dir/src/a.cpp.o
/home/totoro/catkin_ws/devel/lib/liba.so: auv/CMakeFiles/a.dir/build.make
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/libroscpp.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/librosconsole.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/librostime.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/libcpp_common.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/totoro/catkin_ws/devel/lib/liba.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/totoro/catkin_ws/devel/lib/liba.so: /opt/ros/kinetic/lib/libserial.so
/home/totoro/catkin_ws/devel/lib/liba.so: auv/CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/totoro/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/totoro/catkin_ws/devel/lib/liba.so"
	cd /home/totoro/catkin_ws/build/auv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
auv/CMakeFiles/a.dir/build: /home/totoro/catkin_ws/devel/lib/liba.so

.PHONY : auv/CMakeFiles/a.dir/build

auv/CMakeFiles/a.dir/requires: auv/CMakeFiles/a.dir/src/a.cpp.o.requires

.PHONY : auv/CMakeFiles/a.dir/requires

auv/CMakeFiles/a.dir/clean:
	cd /home/totoro/catkin_ws/build/auv && $(CMAKE_COMMAND) -P CMakeFiles/a.dir/cmake_clean.cmake
.PHONY : auv/CMakeFiles/a.dir/clean

auv/CMakeFiles/a.dir/depend:
	cd /home/totoro/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/totoro/catkin_ws/src /home/totoro/catkin_ws/src/auv /home/totoro/catkin_ws/build /home/totoro/catkin_ws/build/auv /home/totoro/catkin_ws/build/auv/CMakeFiles/a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : auv/CMakeFiles/a.dir/depend

