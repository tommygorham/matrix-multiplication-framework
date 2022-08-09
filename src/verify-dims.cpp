#include "dense-matrix.h"
#include "verify-dims.h"
#include <iostream>

template <typename T>
int verify_Dims(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B) // C := A * B
{
  // check for compatibility of A, B, and C:
  if (C.Rows() != A.Rows() ||
      C.Cols() != B.Cols() ||
      A.Cols() != B.Rows())
  {
    // print error message if we cannot do the multiplication
    std::cout << "verify_Dims(): Invalid dimensions " << std::endl;
    return -1;
  }
  return 0; 
}
//
// specific instantiation 
// 
template int verify_Dims(dense_Matrix<float> &C, const dense_Matrix<float> &A, const dense_Matrix<float> &B);// C := A * B
