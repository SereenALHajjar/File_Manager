cmake_minimum_required(VERSION 3.15)

project(Task2)

add_executable(file_manager main.cpp cd.cpp ls.cpp cp.cpp mkdir.cpp mv.cpp)

# add_library(Change_Directory_lib cd.cpp)