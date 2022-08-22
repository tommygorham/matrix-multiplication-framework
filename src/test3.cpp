//  trying to optimize the transpose  

#include <iostream>        // cout, endl
using std::cout; 
using std::endl; 
#include "dense-matrix.h"  // martix definition
#include "matrix-mult.h"   // traditional approach 
#include <string_view> 
/*
#include <chrono>          // high_resolution_timer
#include <typeinfo>        // typeid for DEBUG 
#include <type_traits>     // static_assert 
#include <random>          // std::mt19937
#include <cassert>         // assert() 
#include <string>          // for read/write output  
#include "matrix-mult.h"   // traditional approach 
#include "verify-types.h"  // ensure T * T 
#include "verify-dims.h"   // per matrix mult definition  
#include "timer.h"         // scope-based chrono high_resolution_timer
#include "writecsv.h"      // write output to csv
#include "terminal.h"      // write output to terminal 
#include "readtype.h"      // decltype() 
*/ 
const int M = 10; // rows  
const int N = 10; // cols 

// #pragma pack(1) // no padding 

#define DEFAULT_INPUT "./test3" 
#define ACCESSMETHOD  "heap allocated 1D RowMajor" 

int main(int argc, char **argv)
{ 
    // setup 
    using val_type = int; 
    std::string_view am = ACCESSMETHOD; 
    std::string filename = DEFAULT_INPUT; 
    std::string_view vt = typeid(val_type).name(); // store the datatype of the matrix for results 
	val_type fill = 1; 
	dense_Matrix<val_type> A(M, N), B(M, N), C(M, N); 
	for (int i = 0; i < M; ++i) {
       for (int j = 0; j < N; ++j){ 
		   A(i,j)= fill; 
           if(i == j){ 
			   B(i,j) = 3; 
		   } 
		   else{ 
			   B(i,j) = 0; 
		   } 
		   fill += 1; 
       }
	} 
    
	dense_Matrix<int> tmp(M,N);  
    for (int i = 0; i < M; ++i) {
       for (int j = 0; j < N; ++j){  
          tmp(i,j) = A(j,i); // transpose  
	   }
    }
	
	A.Print(); 
	B.Print(); 
	tmp.Print(); 

	/*
    // multiply 
    for (int i = 0; i < M; ++i){
	  for(int j = 0; j < N; ++j){  
		for(int k = 0; k < N; ++k){ 
			  C(i,j) += A(i,k) * B(j,k); 
		  }
      }
  }*/ 

return 0; 
}

