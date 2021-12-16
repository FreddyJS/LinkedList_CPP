cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

# Set the project name
project(LinkedListLib)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(DOXYGEN_GENERATE_HTML YES)
  set(DOXYGEN_HTML_OUTPUT ${CMAKE_SOURCE_DIR}/docs)
  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${CMAKE_SOURCE_DIR}/README.md)
  set(DOXYGEN_EXCLUDE_PATTERNS 
    */build/*
    */tests/*
    */docs/*
  )

  doxygen_add_docs(
    doxygen
    ${CMAKE_SOURCE_DIR}
    COMMENT "Generating doc pages"
  )
endif(DOXYGEN_FOUND)

# Declarate our header only library
add_library(linkedlist INTERFACE)
target_include_directories(linkedlist INTERFACE linkedlist/)
target_sources(linkedlist INTERFACE 
  ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist/LinkedList.hpp
)

# Enable testing if needed and setup tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
