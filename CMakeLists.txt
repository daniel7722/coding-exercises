cmake_minimum_required(VERSION 3.28)
project(coding_exercises)

set(CMAKE_CXX_STANDARD 14)

add_executable(coding_exercises
        Algorithm/sorting.cpp
        Dynamic-Programming/longest_increasing_subsequence.cpp
)
