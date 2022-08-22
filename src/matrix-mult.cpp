#include "dense-matrix.h"
#include "matrix-mult.h"

// naive, ijk: C := A * B
template <typename T> 
void matrix_Mult(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B) 
{  
  for (int i = 0; i < C.Rows(); ++i) // row-wise
  {
    for (int j = 0; j < C.Cols(); ++j) // col-wise
    {
      // compute C(i,j):
      T temp = 0;
      for (int k = 0; k < A.Cols(); ++k)
      {
        temp += A(i, k) * B(k, j);    
      }
      C(i, j) = temp; // assign at fixed position i,j
    }
  }
}

// transpose B: C := A * B
template <typename T> 
void matrix_Mult2(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B, const int M, const int N)  
{  
  // transpose 
  dense_Matrix<T> tmp(M,N);  
  for (int i = 0; i < M; ++i) // row-wise
  {
    for (int j = 0; j < N; ++j) // col-wise
    {
      tmp(i,j) = B(j,i); // transpose B 
	}
  }
  // multiply 
  for (int i = 0; i < M; ++i)
  {
	  for(int j = 0; j < N; ++j) 
	  { 
		  for(int k = 0; k < N; ++k)
		  { 
			  C(i,j) += A(i,k) * tmp(j,k); 
		  }
      }
  }
}

//
// specific instantiation:
//
// template void matrix_Mult(dense_Matrix<float> &C, const dense_Matrix<float> &A, const dense_Matrix<float> &B);// C := A * B
// template void matrix_Mult2(dense_Matrix<float> &C, const dense_Matrix<float> &A, const dense_Matrix<float> &B, const int M, const int N);// C := A * B
