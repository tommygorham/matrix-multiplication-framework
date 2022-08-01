#include "dense-matrix.h"
#include "matrix-mult.h"
#include <iostream>

//#define DEBUG

using namespace std;
template <typename T>
int matrix_Mult(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B) // C := A * B
{
  // check for compatibility of A, B, and C:
  if (C.Rows() != A.Rows() ||
      C.Cols() != B.Cols() ||
      A.Cols() != B.Rows())
  {
    // print error message if we cannot do the multiplication
    std::cout << "matrix_Mult(): Invalid dimensions " << std::endl;
    return -1;
  }

  // do the multiplication:
  for (int i = 0; i < C.Rows(); ++i)
  {
    for (int j = 0; j < C.Cols(); ++j)
    {
      // compute C(i,j):
      float temp = 0.0;
      //cout << "Processing element:" << i << "," << j << endl;
      for (int k = 0; k < A.Cols(); ++k)
      {
        temp += A(i, k) * B(k, j);
        //cout << "k= " << k << "   A(i,j): " << A(i, j) << ", "
            // << "B(k,j): " << B(k, j) << ", " << temp << endl;
      }

      C(i, j) = temp;

#ifdef DEBUG
      cout << "Just assigned C(" << i << "," << j << ") = " << C(i, j) << endl;
#endif
    }
  }
  return 0; // no error
}

//
// specific instantiation:
//
template int matrix_Mult(dense_Matrix<double> &C, const dense_Matrix<double> &A, const dense_Matrix<double> &B);// C := A * B
