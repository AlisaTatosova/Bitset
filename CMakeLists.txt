cmake_minimum_required(VERSION 3.10)
project(Bitset)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)

add_executable(bitset main.cpp)
add_executable(run_tests 
    tests/test_7bit_bitset.cpp
    tests/test_23bit_bitset.cpp
    tests/test_64bit_bitset.cpp
)

target_link_libraries(run_tests gtest gtest_main)

