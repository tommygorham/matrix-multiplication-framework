#include "dense-matrix.h"
#include "matrix-mult.h"
//#include <iostream>

//#define DEBUG

// naive, ijk
template <typename T> 
void matrix_Mult(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B) // C := A * B
{  
  for (int i = 0; i < C.Rows(); ++i) // row-wise
  {
    for (int j = 0; j < C.Cols(); ++j) // col-wise
    {
      // compute C(i,j):
      T temp = 0;
      //  cout << "Processing element:" << i << "," << j << endl;
      for (int k = 0; k < A.Cols(); ++k)
      {
        temp += A(i, k) * B(k, j);    
		//cout << "k= " << k << "   A(i,j): " << A(i, j) << ", "
        //    << "B(k,j): " << B(k, j) << ", " << temp << endl;
      }
      C(i, j) = temp; // fixed i,j
//	  std::cout << "\nJust assigned C( " << i << ", " << j << " ): " << C(i,j); 
    }
  }
}

//
// specific instantiation:
//
 template void matrix_Mult(dense_Matrix<float> &C, const dense_Matrix<float> &A, const dense_Matrix<float> &B);// C := A * B
