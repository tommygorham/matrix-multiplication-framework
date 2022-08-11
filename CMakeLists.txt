cmake_minimum_required(VERSION 3.16) 

project(matrix-multiplication-framework) 
include_directories(include) 
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -O2 ") 

### TEST 1 
#add_executable(serial_naive_noopt.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 

#if -O2 enabled 
add_executable(serial_naive_O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 

#add_executable(serial_transpose_noopt.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2.cpp) 

#if O2 enabled 
add_executable(serial_transpose_O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2.cpp) 
### END TEST 1 ###
