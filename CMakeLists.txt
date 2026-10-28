cmake_minimum_required(VERSION 3.26)

project(cpp_sma LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(sma_lib STATIC src/sma.cpp)
target_include_directories(sma_lib PUBLIC include)

add_executable(sma_app app/main.cpp)
target_link_libraries(sma_app PRIVATE sma_lib)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sma_tests tests/sma_test.cpp)
target_link_libraries(sma_tests PRIVATE sma_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(sma_tests)