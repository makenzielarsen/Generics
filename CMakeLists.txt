cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.h Dictionary.cpp KeyValue.h KeyValue.cpp)
add_executable(HW6 ${SOURCE_FILES})