cmake_minimum_required(VERSION 3.20)

project(TimeMeter LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(TimeMeter src/lin.cpp src/main.cpp src/win.cpp src/Timer.cpp)