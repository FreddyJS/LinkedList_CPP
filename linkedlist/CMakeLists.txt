SET(LIST_SOURCES
    ./LinkedList.cpp
)

include_directories(include)
add_library(LinkedList STATIC ${LIST_SOURCES})