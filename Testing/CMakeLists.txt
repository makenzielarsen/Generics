cmake_minimum_required(VERSION 3.6)
project(Testing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES testingMain.cpp)
add_executable(Testing ${SOURCE_FILES})