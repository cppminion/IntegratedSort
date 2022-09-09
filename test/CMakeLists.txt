cmake_minimum_required(VERSION 3.14)

set(This SortingTest)
project(${This} CXX)

include(GoogleTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_GENERATOR "Unix Makefiles")

set(Sources
        ../src/merge_sort.cpp
        ../src/insertion_sort.cpp
        ../src/integrated_sort.cpp
)
set(Tests
        merge_sort_test.cpp
        insertion_sort_test.cpp
        integrated_sort_test.cpp
)

add_executable(${This} ${Sources} ${Tests})

target_link_libraries(
        ${This} PUBLIC
        gtest_main
)

add_test(
        NAME ${This}
        COMMAND ${This}
)