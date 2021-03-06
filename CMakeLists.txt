cmake_minimum_required(VERSION 3.4.3 FATAL_ERROR)
project(PiAlarm)

# The version number
set(PiAlarm_VERSION_MAJOR 0)
set(PiAlarm_VERSION_MINOR_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -m64 -g")
INCLUDE_DIRECTORIES(irrKlang-1.5.0/include)
INCLUDE_DIRECTORIES(rapidxml-1.13)
LINK_DIRECTORIES(irrKlang-1.5.0/bin)

set(SOURCE_FILES main.cpp Source/SoundPlayer.cpp Source/SoundPlayer.h
        Source/Utils/Helper.cpp Source/Utils/Helper.h Source/ISoundMode.h Source/WakeUpMode.cpp
        Source/WakeUpMode.h Source/StandardMode.cpp Source/StandardMode.h Source/Utils/Scheduler.cpp
        Source/Utils/Scheduler.h Source/Utils/ITask.h Source/Utils/ScheduleTask.cpp
      Source/Utils/ScheduleTask.h Source/AlarmController.cpp Source/AlarmController.h Source/AlarmTask.cpp Source/AlarmTask.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(PiAlarm ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(PiAlarm libIrrKlang.so)
