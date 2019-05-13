cmake_minimum_required(VERSION 3.13)
project(Assignment3_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment3_1_C Main1.c roofDataStructures/RoofTree.c roofDataStructures/RoofTree.h roofDataStructures/Roof.c roofDataStructures/Roof.h roofDataStructures/waterCalc.h roofDataStructures/waterCalc.c)
add_executable(Assignment3_3_C)