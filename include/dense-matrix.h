#ifndef _DENSE_MATRIX_H
#define _DENSE_MATRIX_H

template <typename T>
class dense_Matrix  
{
 public:

  // constructor
  dense_Matrix(int _M, int _N) : M(_M), N(_N), array(new T[_M*_N]) {}

  //  copy constructor
  //  dense_Matrix<T>(const dense_Matrix<T> &DM); 
  
  // overload assignment for copy 
  dense_Matrix<T> &operator=(const dense_Matrix<T> &rhs); 

  // destructor
  virtual ~dense_Matrix() {delete[] array;}
  
  // operator()(int i, int j)
  T &operator()(int i, int j) {return array[i*N+j]; } // row major
  T operator()(int i, int j) const {return array[i*N+j]; } // row major [R/O]

  void Resize(int Mprime, int Nprime);
  
  int Rows() const {return M;}
  int Cols() const {return N;}

 private:
  // need size values: M rows, N columns
  int M, N;
  T *array;

};


#endif
