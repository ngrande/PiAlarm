cmake_minimum_required(VERSION 3.3)
project(PiAlarm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -m64")
INCLUDE_DIRECTORIES(irrKlang-64bit-1.5.0/include)
LINK_DIRECTORIES(irrKlang-64bit-1.5.0/bin/linux-gcc-64)

set(SOURCE_FILES main.cpp Source/MusicPlayer.cpp Source/MusicPlayer.h Source/FileHelper.cpp Source/FileHelper.h Source/ISoundMode.h Source/WakeUpMode.cpp Source/WakeUpMode.h Source/StandardMode.cpp Source/StandardMode.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(PiAlarm ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(PiAlarm libIrrKlang.so)