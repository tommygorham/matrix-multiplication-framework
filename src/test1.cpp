#include <iostream>
#include "dense-matrix.h"
#include "matrix-mult.h"

using namespace std;

template <typename T> 
void print_dense_Matrix(const dense_Matrix<T> &A)
{
  for (int i = 0; i < A.Rows(); ++i)
  {
    for (int j = 0; j < A.Cols(); ++j)
    {
      std::cout << A(i, j) << " ";
    }
    std::cout << ("\n");
  }
  std::cout << ("\n"); // white space
}
template <typename T> 
void init_dense_Matrix_const(dense_Matrix<T> &A, const T& c)
{
  for (int i = 0; i < A.Rows(); ++i)
  {
    for (int j = 0; j < A.Cols(); ++j)
    {
      A(i, j) = c;
      std::cout << A(i, j) << " ";
    }
    std::cout << ("\n");
  }
  std::cout << ("\n"); // white space
}

int main(int argc, char **argv)
{
  dense_Matrix<double> A(100, 100), B(100, 100), C(100, 100);
  dense_Matrix<double> AA(A.Rows(),A.Cols());

  // fill in matrix A
  std::cout << "Matrix A: " << ("\n"); // for readability 
  init_dense_Matrix_const(A, 2.0);
  std::cout << ("\n"); // white space

  // fill in matrix B
  std::cout << "Matrix B: " << ("\n"); // for readability
  for (int i = 0; i < B.Rows(); ++i)
  {
    for (int j = 0; j < B.Cols(); ++j)
    {
      if(i == j)
         B(i, j) = 3;
      else
	 B(i, j) = 0.;

      std::cout << B(i, j) << " ";
    }
    std::cout << ("\n");
  }

  int code = matrix_Mult(C, A, B);

std::cout << "the return code was " << code << std::endl;
//int code = matrix_Mult(C, A, Bprime);
  // print C out (how?)
std::cout << ("\n"); 
std::cout << "Matrix C: " << ("\n"); // for readability
 for (int i = 0; i < C.Rows(); ++i)
  {
    for (int j = 0; j < C.Cols(); ++j)
    {
      std::cout << C(i,j) << " ";
    }
    std::cout << ("\n");
  }

  //
  AA = A; // calls AA.operator=(A);

  // delete D;
  return 0;
}
