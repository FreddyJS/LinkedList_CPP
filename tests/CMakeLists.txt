# Enable testing and set tests
enable_testing()

set(TEST_SOURCES 
  main.cpp
  integer_list.cpp
)

add_executable(list_tests ${TEST_SOURCES})
target_link_libraries(list_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(list_tests)
