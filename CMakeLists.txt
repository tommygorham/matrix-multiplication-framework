cmake_minimum_required(VERSION 3.16) 

project(matrix-multiplication-framework) 
include_directories(include) 
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -O2 ") 

### TEST 1: BASELINE for naive (serial ijk) and transpose ###
#add_executable(serial_naive_noopt.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 
#add_executable(serial_transpose_noopt.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2.cpp) 

# NOTE: if -O2 enabled via end of line 5 above 
add_executable(serial_naive_O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test1.cpp) 
add_executable(serial_transpose_O2.exe src/verify-dims.cpp src/verify-types.cpp src/dense-matrix.cpp src/matrix-mult.cpp src/terminal.cpp src/writecsv.cpp src/test2.cpp) 
### END TEST 1 ###