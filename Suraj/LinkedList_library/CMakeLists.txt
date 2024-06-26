cmake_minimum_required(VERSION 3.10)
project(LinkedList_library C)

# Specify the library
add_library(LinkedList_library STATIC src/LinkedList)

# Include directories
target_include_directories(LinkedList_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
