cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

# Set the project name
project(LinkedList)

# Declarate our header only library
add_library(linkedlist INTERFACE)
target_include_directories(linkedlist INTERFACE linkedlist/)


# Add the tests dir
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()