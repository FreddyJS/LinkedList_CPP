# Enable testing and set tests
# Get the Google Test Lib
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES 
  main.cpp
  integer_list.cpp
)

add_executable(list_tests ${TEST_SOURCES})
target_link_libraries(list_tests gtest_main linkedlist)

include(GoogleTest)
gtest_discover_tests(list_tests)
