cmake_minimum_required(VERSION  3.25)
project(
    libskeleton
    VERSION 0.0.1
    LANGUAGES CXX)

include(FetchContent)
include(GNUInstallDirs)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)

set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_Declare(googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.7.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(googlebenchmark googletest)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_subdirectory(benchmark)
add_subdirectory(examples)
add_subdirectory(src/libskeleton)
add_subdirectory(tests)
