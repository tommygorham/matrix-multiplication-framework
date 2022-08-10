cmake_minimum_required(VERSION 3.16) 

project(matrix-multiplication-framework) 
include_directories(include) 
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a ") 

add_executable(run-test1.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 

#add_executable(run-test1-O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 

add_executable(run-test2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2_transpose.cpp)

#add_executable(run-test2-O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2_transpose.cpp)
