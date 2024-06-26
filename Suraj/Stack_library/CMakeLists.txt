cmake_minimum_required(VERSION 3.10)
project(Stack_library C)

# Specify the library
add_library(Stack_library STATIC src/stack.c)

# Include directories
target_include_directories(Stack_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
