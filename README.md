# matrix-multiplication-framework
Framework for building high-performance matrix-multiplication codes with C++. 

# Develop Branch 
* In this branch, a Move Contructor/Assignment has been added to see if transpose multiply can be even faster. 
* Also redefined dense_matrix.h to include definitions, thus avoiding explicit instantiation 

# Directions 
* Until more handling is added for cross-platform tests, the preferred way to build this is with CMake and GCC or Clang on Linux 


`mkdir build && cd build`
```
cmake .. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang
```
`
make 
`
