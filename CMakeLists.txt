cmake_minimum_required(VERSION 3.16) 

project(matrix-multiplication-framework) 
include_directories(include) 
set(CMAKE_CXX_FLAGS "-Wall -std=c++2a -O2 " ) 

add_executable(run-test1-O2.exe src/dense-matrix.cpp src/matrix-mult.cpp src/test1.cpp) 
#add_executable(run-test2.exe src/dense-matrix.cpp src/matrix-mult.cpp src/test2_readmat.cpp) 
### TODO 
#add_executable(pygemm_monotonic.exe src/pygemm.py) 
#add_executable(pygemm_perfcounter.exe src/pygemm2.py) 

