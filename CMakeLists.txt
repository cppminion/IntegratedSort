CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

set(This IntegratedSort)
project(${This} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_GENERATOR "Unix Makefiles")

set( SOURCES
        src/main.cpp
)

add_executable(${This} ${SOURCES})

# google test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(test)