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
// #include "readtype.h"   // decltype() 

constexpr int M = 100; // rows  
constexpr int N = 100; // cols 

// #pragma pack(1) // no padding 

int main(int argc, char **argv)
{
	// input 
    using val_type = float; 
	std::mt19937 gen(0); // seed with 0 to produce same random matrix  
	std::uniform_real_distribution<val_type> dist(1.0,2.0); 
	dense_Matrix<val_type> A(M, N), B(M, N), C(M, N);
    for(auto& v : A) v = dist(gen); 
	B.init_diag(2.0f);             

    // validate input
    int valid_types = verify_Types(A,B); 
    int valid_dims = verify_Dims(C,A,B); 
    assert(valid_dims == 0 && valid_types == 0); 
         
    // compute 
	{ 
        TommysLib::Timer timer; // scope-based timer
        matrix_Mult(C, A, B);   // multiply C = A*B 
    }
 
    // print result, max row/col is 25 for printing 
    cout << "\nMatrix A: " << ("\n"); // for readability
    A.Print(); 
    cout << "\nMatrix B: " << ("\n"); // for readability
    B.Print(); 
    cout << "\nMatrix C: " << ("\n"); // for readability
    C.Print(); 
  
/*#ifdef DEBUG 
  int valid_types = verify_Types(A,B); 
  int valid_dims = verify_Dims(C,A,B); 
  assert(valid_dims == 0 && valid_types == 0); 
  cout << "\nsizeof(A): " <<  sizeof(A) << endl;
  cout << "\nsizeof(&A): " <<  sizeof(&A) << endl; // ptr + int + int, int default to 8 because padding 
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
  // dense_Matrix<double> AA(A.Rows(),A.Cols());
  // AA = A; // calls AA.operator=(A);
 */ 
 return 0;
}
