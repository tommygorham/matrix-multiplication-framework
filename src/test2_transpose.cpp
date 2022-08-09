// program name:  test2_transpose.cpp 
// description:   to measure memory access time of a heap allocated 2D matrix 
//                in general matrix multiplication (C=A*B),  where the matrix 
//                is defined via a pointer to 1D data. This data is stored in 
//                row-major order for optimal CPU execution, and the templated
//                matrix class uses  explicit instantiation for float values. 
//
// significance:  though dense_Matrix A is accessed sequentially in test1.cpp,
//                the inner loop advances the row number of B. Therefore, 
//                "transposing" B before computing enables both matrices to be
//                accessed sequentially, and avoids expensive non-sequential 
//                accesses per column

#include <iostream>        // cout, endl
using std::cout; 
using std::endl; 
#include <chrono>          // high_resolution_timer
#include <typeinfo>        // typeid for DEBUG 
#include <type_traits>     // static_assert 
#include <random>          // std::mt19937
#include <cassert>         // assert() 
#include "dense-matrix.h"  // martix definition
#include "matrix-mult.h"   // traditional approach 
#include "verify-types.h"  // ensure T * T 
#include "verify-dims.h"   // per matrix mult definition  
#include "timer.h"         // scope-based chrono high_resolution_timer
// #include "readtype.h"      // decltype() 

const int M = 3; // rows  
const int N = 3; // cols 

// #pragma pack(1) // no padding 

int main(int argc, char **argv)
{
	// input 
    using val_type = float; 
	std::mt19937 gen(0); // seed with 0 to produce same random matrix  
	std::uniform_real_distribution<val_type> dist(1.0f,2.0f); 
	dense_Matrix<val_type> A(M, N), B(M, N), C(M, N);
    for(auto& v : A) v = dist(gen); // fill A with random floats   
    for(auto& y : B) y = dist(gen); // fill B with random floats   
    
	// compute 
	{ 
        TommysLib::Timer timer; // scope-based timer
        matrix_Mult2(C, A, B, M, N);   // multiply C = A*B 
    }
 
    // validate compute by printing result, NOTE: this is safe for large 
	// matrices, as maximum values to print is capped at 25  
    cout << "\nMatrix A: " << ("\n"); // for readability
    A.Print(); 
    cout << "\nMatrix B: " << ("\n"); // for readability
    B.Print(); 
    cout << "\nMatrix C: " << ("\n"); // for readability
    C.Print(); // result
   
    return 0; 
}  
