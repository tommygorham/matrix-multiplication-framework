cmake_minimum_required(VERSION 3.16) 

project(matrix-multiplication-framework) 
include_directories(include) 
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a " ) 

add_executable(run.exe src/dense-matrix.cpp src/matrix-mult.cpp src/test2_readmat.cpp) 
