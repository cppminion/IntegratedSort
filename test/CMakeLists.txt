cmake_minimum_required(VERSION 3.14)

set(This SortComp)
project(${This})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_GENERATOR "Unix Makefiles")

set(Sources
        src/main.cpp
        src/helpers.hpp 
        src/sorting.hpp)

add_executable(${This} ${Sources})
