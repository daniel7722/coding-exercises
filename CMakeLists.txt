cmake_minimum_required(VERSION 3.28)
project(coding_exercises)

set(CMAKE_CXX_STANDARD 14)

add_executable(coding_exercises
        Algorithm/sorting.cpp
        Dynamic-Programming/longest_increasing_subsequence.cpp
        Dynamic-Programming/longest_common_subsequence.cpp
        Trie/replace_word.cpp
        Array-and-Hashing/continuous_subarray_sum.cpp
        Array-and-Hashing/relative_sort_array.cpp
        Two-Pointers/sort_colors.cpp
        Array-and-Hashing/minimum_number_of_moves_to_seat_everyone.cpp
        Two-Pointers/sum_of_square_number.cpp
)
