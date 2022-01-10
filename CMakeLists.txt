cmake_minimum_required(VERSION 3.21)
project(MazeGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(mazegenerator main.cpp cell.h cell.cpp grid.cpp grid.h)
