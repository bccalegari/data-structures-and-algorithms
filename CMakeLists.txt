cmake_minimum_required(VERSION 3.29)
project(data_structures_and_algorithms C)

set(CMAKE_C_STANDARD 23)

add_executable(data_structures_and_algorithms main.c)

add_library(vector STATIC vector/vector.c vector/vector.h)

add_executable(vector_test vector/vector_tests.c)

target_link_libraries(vector_test vector)