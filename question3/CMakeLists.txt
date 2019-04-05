cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project (FindDuplicateNumbersInArray)

set(CMAKE_CXX_STANDARD 14)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
