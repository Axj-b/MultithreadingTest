# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(YourProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all source files in the src directory
file(GLOB SOURCES src/*.cpp)

# Add an executable target
add_executable(MultithreadingApp
 ${SOURCES}
 main.cpp
 )


