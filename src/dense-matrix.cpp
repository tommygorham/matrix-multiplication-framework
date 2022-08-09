#include "dense-matrix.h"
#include <iostream> 
#include <iomanip> 

// = operator 
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

// resize method 
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

// print matrix 
template <typename T> 
void dense_Matrix<T>::Print(){
	std::cout << (*this).Rows() << " Rows " << (*this).Cols() << " Columns\n"; 
    if ((*this).Rows() < 25 && (*this).Cols() < 25){ 
    	for (int i = 0; i < (*this).Rows(); ++i){
			for (int j = 0; j < (*this).Cols(); ++j){
      			std::cout << std::setw(8) << std::fixed <<  (*this)(i, j) << " ";
    		}
    		std::cout << ("\n");
  		}
  	  std::cout << ("\n"); 
	} else {
		std::cout << "Printing first 25 values\n"; 
		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
      			std::cout << std::setw(8) << std::fixed <<  (*this)(i, j) << " ";
    		}
    		std::cout << ("\n");
  		}
  		std::cout << ("\n"); 
	}
} 

// init with specific value 
template <typename T> 
void dense_Matrix<T>::init_with_const_val(const T& fill){
  for (int i = 0; i < (*this).Rows(); ++i){
    for (int j = 0; j < (*this).Cols(); ++j){
      (*this)(i, j) = fill;
    }
  }
}

// init where only non-zero values are on the diagonal 
template <typename T> 
void dense_Matrix<T>::init_diag(const T& fill){
	T zero = 0; 
	for (int i = 0; i < (*this).Rows(); ++i){
    	for (int j = 0; j < (*this).Cols(); ++j){
	    	if(i == j)
           	  (*this)(i, j) = fill; // fill diaganol with specified value 
            else
	          (*this)(i, j) = zero;  // fill the rest with 0 using appropriate type
        }
    }
}

//
// specific instantiation:
//
 template class dense_Matrix<float>;
