cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)

# Set the project name
project(LinkedList)

# Get the Google Test Lib
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the tests dir
include_directories(linkedlist)

add_subdirectory(tests)
