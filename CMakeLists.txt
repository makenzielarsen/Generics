cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Dictionary.h
        KeyValue.h
        UserInterface.cpp UserInterface.h)
add_executable(HW6 main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/testingMain.cpp
        Testing/testDictionary.h
        Testing/testKeyValue.h
        Testing/testKeyValuePair.cpp Testing/testDictionary.cpp)

add_executable(Test Testing/testingMain.cpp ${SOURCE_FILES} ${TEST_FILES})