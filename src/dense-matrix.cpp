#include "dense-matrix.h"

template <typename T> 
dense_Matrix<T> &dense_Matrix<T>::operator=(const dense_Matrix<T> &rhs) // don't allow it for now.
{
  Resize(rhs.Rows(),rhs.Cols());

  for(int i = 0; i < (*this).Rows(); ++i)
    for(int j = 0; j < (*this).Cols(); ++j)
    {
      //      (*this)(i,j) = rhs(i,j);
      this->operator()(i,j) = rhs(i,j);
    }

  return *this;
}
template <typename T> 
void dense_Matrix<T>::Resize(int Mprime, int Nprime)
{
  if(M*N != Mprime*Nprime)
  {
    delete[] array;
    array = new T[Mprime*Nprime];
  }
  M = Mprime;
  N = Nprime;

}

//
// specific instantiation:
//
template class dense_Matrix<double>;
