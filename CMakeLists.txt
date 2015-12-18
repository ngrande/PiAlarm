cmake_minimum_required(VERSION 3.3)
project(PiAlarm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -m64")
INCLUDE_DIRECTORIES(irrKlang-64bit-1.5.0/include)
INCLUDE_DIRECTORIES(rapidxml-1.13)
LINK_DIRECTORIES(irrKlang-64bit-1.5.0/bin/linux-gcc-64)

set(SOURCE_FILES main.cpp Source/SoundPlayer.cpp Source/SoundPlayer.h Source/Utils/Helper.cpp Source/Utils/Helper.h Source/ISoundMode.h Source/WakeUpMode.cpp Source/WakeUpMode.h Source/StandardMode.cpp Source/StandardMode.h Source/Utils/Scheduler.cpp Source/Utils/Scheduler.h Source/Utils/ITask.h Source/Utils/ScheduleTask.cpp Source/Utils/ScheduleTask.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(PiAlarm ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(PiAlarm libIrrKlang.so)