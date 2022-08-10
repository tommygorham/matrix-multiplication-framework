// program name: test1.cpp 
// description:  To measure memory access time of a heap allocated 2D 
// matrix in general matrix multiplication (C=A*B),  where the matrix 
// is defined via a pointer to 1D data. This data is  stored row-major 
// for optimal CPU execution, and the templated matrix class uses 
// explicit instantiation for float values 

#include <iostream>        // cout, endl
using std::cout; 
using std::endl; 
#include <iomanip> 
#include <chrono>          // high_resolution_timer
#include <typeinfo>        // typeid for DEBUG 
#include <type_traits>     // static_assert 
#include <random>          // std::mt19937
#include <cassert>         // assert() 
#include <string> 
#include <string_view> 
#include <fstream> 
#include "dense-matrix.h"  // martix definition
#include "matrix-mult.h"   // traditional approach 
#include "verify-types.h"  // ensure T * T 
#include "verify-dims.h"   // per matrix mult definition  
#include "timer.h"         // scope-based chrono high_resolution_timer
#include "writecsv.h" 
#include "terminal.h" 
#include "readtype.h"      // decltype() 

const int M = 100; // rows  
const int N = 100; // cols 

// #pragma pack(1) // no padding 

#define DEFAULT_INPUT "./test1" 
#define ACCESSMETHOD  "heap allocated 1D RowMajor" 

int main(int argc, char **argv)
{ 
    // setup 
    using val_type = float; 
    std::string_view am = ACCESSMETHOD; 
    std::string filename = DEFAULT_INPUT; 
    std::string_view vt = typeid(val_type).name(); // store the datatype of the matrix for results 
    std::mt19937 gen(0); // seed with 0 to produce same random matrix  
	std::uniform_real_distribution<val_type> dist(1.0f,2.0f); 
	dense_Matrix<val_type> A(M, N), B(M, N), C(M, N);
    for(auto& v : A) v = dist(gen); // fill A with random floats   
    for(auto& y : B) y = dist(gen); // fill B with random floats  
    
	// validate input 
	int valid_types = verify_Types(A,B); 
	int valid_dims  = verify_Dims(C,A,B); 
    assert(valid_dims == 0 && valid_types == 0); // 0 means no error here 

    // compute with scope-based timer 
    //	{ to use scope based TommysLib::Timer timer; 
    //    scope-based timer, chrono::high_res_clock
    //    matrix_Mult(C, A, B);   // multiply C = A*B 
    //  }
   // compute 
   auto st = std::chrono::high_resolution_clock::now(); 
   matrix_Mult(C, A, B);   // multiply C = A*B 
   auto et = std::chrono::high_resolution_clock::now(); 
   std::chrono::duration<double, std::milli> mm_time = et - st; 

#ifdef DEBUG 
   	B.init_diag(2.0f); // to easily confirm accuracy of multiplication              
    cout << "\nsizeof(A): " <<  sizeof(A) << endl;
	cout << "\nsizeof(&A): " <<  sizeof(&A) << endl; // ptr + int + int, int defaults to 8 b/c of padding 
	cout << "\ntype(A): " <<  typeid(A).name() << endl; 
	cout << "\ntype(&A): " <<  typeid(&A).name() << endl; 
    // cout << "\nreadtype(A): " <<  type_name<decltype(A)>() << endl; 
	cout << "\n&A: " <<  &A << endl;   
	cout << "\n&A(0,0): " <<  &A(0,0) << "  " << A(0,0) << endl; 
	cout << "\n&A(0,1): " <<  &A(0,1) << "  " << A(0,1) << endl; 
	cout << "\n&A(1,0): " <<  &A(1,0) << "  " << A(1,0) << endl; 
	cout << "\n&A(2,0): " <<  &A(2,0) << "  " << A(2,0) << endl; 
	cout << "\n\nAlignment of matrix A: " << alignof(A) << endl; 
#endif     
    
    // prepare profiling results
    std::string_view declaration = type_name<decltype(A)>(); 
	std::size_t bytes = sizeof(A) +  (M * N)*sizeof(val_type); 
    std::size_t elements = M*N; 
 
    // write profiling results 
    writeToTerminal(declaration, vt, bytes, elements, mm_time, am);   
    if (argc == 2)  {
        std::string file_path(argv[1]);
        writeToCSV(file_path, filename, vt, elements, bytes, mm_time, am); 
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
