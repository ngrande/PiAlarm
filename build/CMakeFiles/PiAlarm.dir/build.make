# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ngrande/Projects/ClionProjects/PiAlarm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ngrande/Projects/ClionProjects/PiAlarm/build

# Include any dependencies generated for this target.
include CMakeFiles/PiAlarm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PiAlarm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PiAlarm.dir/flags.make

CMakeFiles/PiAlarm.dir/main.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PiAlarm.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/main.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/main.cpp

CMakeFiles/PiAlarm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/main.cpp > CMakeFiles/PiAlarm.dir/main.cpp.i

CMakeFiles/PiAlarm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/main.cpp -o CMakeFiles/PiAlarm.dir/main.cpp.s

CMakeFiles/PiAlarm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/main.cpp.o.requires

CMakeFiles/PiAlarm.dir/main.cpp.o.provides: CMakeFiles/PiAlarm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/main.cpp.o.provides

CMakeFiles/PiAlarm.dir/main.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/main.cpp.o


CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o: ../Source/SoundPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/SoundPlayer.cpp

CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/SoundPlayer.cpp > CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.i

CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/SoundPlayer.cpp -o CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.s

CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o


CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o: ../Source/Utils/Helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Helper.cpp

CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Helper.cpp > CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.i

CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Helper.cpp -o CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.s

CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o


CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o: ../Source/WakeUpMode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/WakeUpMode.cpp

CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/WakeUpMode.cpp > CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.i

CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/WakeUpMode.cpp -o CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.s

CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o


CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o: ../Source/StandardMode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/StandardMode.cpp

CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/StandardMode.cpp > CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.i

CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/StandardMode.cpp -o CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.s

CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o


CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o: ../Source/Utils/Scheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Scheduler.cpp

CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Scheduler.cpp > CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.i

CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/Scheduler.cpp -o CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.s

CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o


CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o: ../Source/Utils/ScheduleTask.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/ScheduleTask.cpp

CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/ScheduleTask.cpp > CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.i

CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/Utils/ScheduleTask.cpp -o CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.s

CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o


CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o: ../Source/AlarmController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmController.cpp

CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmController.cpp > CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.i

CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmController.cpp -o CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.s

CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o


CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o: CMakeFiles/PiAlarm.dir/flags.make
CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o: ../Source/AlarmTask.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o -c /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmTask.cpp

CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmTask.cpp > CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.i

CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ngrande/Projects/ClionProjects/PiAlarm/Source/AlarmTask.cpp -o CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.s

CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.requires:

.PHONY : CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.requires

CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.provides: CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.requires
	$(MAKE) -f CMakeFiles/PiAlarm.dir/build.make CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.provides.build
.PHONY : CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.provides

CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.provides.build: CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o


# Object files for target PiAlarm
PiAlarm_OBJECTS = \
"CMakeFiles/PiAlarm.dir/main.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o" \
"CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o"

# External object files for target PiAlarm
PiAlarm_EXTERNAL_OBJECTS =

../bin/PiAlarm: CMakeFiles/PiAlarm.dir/main.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/build.make
../bin/PiAlarm: CMakeFiles/PiAlarm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../bin/PiAlarm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PiAlarm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PiAlarm.dir/build: ../bin/PiAlarm

.PHONY : CMakeFiles/PiAlarm.dir/build

CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/main.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/SoundPlayer.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/Utils/Helper.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/WakeUpMode.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/StandardMode.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/Utils/Scheduler.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/Utils/ScheduleTask.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/AlarmController.cpp.o.requires
CMakeFiles/PiAlarm.dir/requires: CMakeFiles/PiAlarm.dir/Source/AlarmTask.cpp.o.requires

.PHONY : CMakeFiles/PiAlarm.dir/requires

CMakeFiles/PiAlarm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PiAlarm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PiAlarm.dir/clean

CMakeFiles/PiAlarm.dir/depend:
	cd /home/ngrande/Projects/ClionProjects/PiAlarm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ngrande/Projects/ClionProjects/PiAlarm /home/ngrande/Projects/ClionProjects/PiAlarm /home/ngrande/Projects/ClionProjects/PiAlarm/build /home/ngrande/Projects/ClionProjects/PiAlarm/build /home/ngrande/Projects/ClionProjects/PiAlarm/build/CMakeFiles/PiAlarm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PiAlarm.dir/depend

