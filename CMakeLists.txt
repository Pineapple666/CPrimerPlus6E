cmake_minimum_required(VERSION 3.20)
project(c_primer_plus_6e C)

set(CMAKE_C_STANDARD 11)

add_executable(example ch01/ex1_1_example.c)
add_executable(concrete ch01/ex1_2_concrete.c)
add_executable(inform ch01/ex1_3_inform.c)
add_executable(test test.c)