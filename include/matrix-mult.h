#ifndef _MATRIX_MULT_H
#define _MATRIX_MULT_H
#include "dense-matrix.h"
template <typename T>
void matrix_Mult(dense_Matrix<T> &C, const dense_Matrix<T> &A, const dense_Matrix<T> &B); // C := A * B
#endif
