cmake_minimum_required(VERSION 3.6)
project(basic_test)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR} ./lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(run_tests
    ./tests/range_test.cpp)

target_link_libraries(run_tests GTest::gtest GTest::gtest_main)

add_test(
    NAME run_tests
    COMMAND run_tests
)
