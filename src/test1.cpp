#include <iostream>
#include "dense-matrix.h"
#include "matrix-mult.h"
#include <chrono> 
#include "timer.h" 
#include <typeinfo> 
#include "readtype.h" 

using namespace std;

template <typename T> 
void print_dense_Matrix(const dense_Matrix<T> &A)
{
  for (int i = 0; i < A.Rows(); ++i)
  {
    for (int j = 0; j < A.Cols(); ++j)
    {
      cout << A(i, j) << " ";
    }
    cout << ("\n");
  }
  cout << ("\n"); // white space
}

template <typename T> 
void init_dense_Matrix_const(dense_Matrix<T> &DM, const T& c)
{
  for (int i = 0; i < DM.Rows(); ++i)
  {
    for (int j = 0; j < DM.Cols(); ++j)
    {
      DM(i, j) = c;
    }
  }
}


template <typename T> 
void init_dense_Matrix_diag(dense_Matrix<T> &DM, const T& c)
{
  for (int i = 0; i < DM.Rows(); ++i)
  {
    for (int j = 0; j < DM.Cols(); ++j)
    {
	    if(i == j)
           DM(i, j) = 4.0;
        else
	       DM(i, j) = 0.;
    }
  }
}

int main(int argc, char **argv)
{
  dense_Matrix<double> A(10, 10), B(10, 10), C(10, 10);
  //dense_Matrix<double> AA(A.Rows(),A.Cols());
  
  // fill in matrix A, B 
  init_dense_Matrix_const(A, 2.0);
  init_dense_Matrix_diag(B, 4.0); 
  
  int code {};   
  { 
    TommysLib::Timer timer; 
    code = matrix_Mult(C, A, B);
  }

  cout << "the return code was " << code << endl;
  
  // print first few rows of C 
  cout << "\nMatrix C: " << ("\n"); // for readability
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      cout << C(i,j) << " ";
    }
    cout << ("\n");
  }
 
  cout << "\nsizeof(A): " <<  sizeof(A) << endl; 
  cout << "\ntype(A): " <<  typeid(A).name() << endl; 
  cout << "\nreadtype(A): " <<  type_name<decltype(A)>() << endl; 
  cout << "\n&A: " <<  &A << endl;   
  cout << "\n&A(0,0): " <<  &A(0,0) << endl; 
  cout << "\n&A(1,0): " <<  &A(1,0) << endl; 

  // AA = A; // calls AA.operator=(A);
  return 0;
}
