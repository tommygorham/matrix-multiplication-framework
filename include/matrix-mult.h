#ifndef _MATRIX_MULT_H
#define _MATRIX_MULT_H
#include "dense-matrix.h"

// naive i,j,k
template <typename T>
void matrix_Mult(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B);  // C := A * B

// transpose B to iterate both matrices sequentially 
template <typename T>
void matrix_Mult2(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B, const int M, const int N); // C := A * B
#endif
