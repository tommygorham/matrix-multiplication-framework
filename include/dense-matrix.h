#ifndef _DENSE_MATRIX_H
#define _DENSE_MATRIX_H

template <typename T>
class dense_Matrix {
private:
  T* array;
  int M, N;

public:
// defined in this file 
  // constructor
  dense_Matrix(int _M, int _N) : M(_M), N(_N), array(new T[_M*_N]) {}
  // copy constructor: dense_Matrix<T>(const dense_Matrix<T> &DM); 

  // destructor
  virtual ~dense_Matrix() {delete[] array;}
  
  // overload operator()
  T &operator()(int i, int j) {return array[i*N+j]; } // row major
  T operator()(int i, int j) const {return array[i*N+j]; } // row major [R/O]

  // explicit accessor 
  int Rows() const {return M;}
  int Cols() const {return N;}

// defined in .cpp 
  // overload assignment for copy 
  dense_Matrix<T> &operator=(const dense_Matrix<T> &rhs); 
  void Resize(int Mprime, int Nprime);
  void Print(); 
  void init_with_const_val(const T& fill); 
  void init_diag(const T& fill); 
  using iterator = T*; 
  iterator begin() { return array; }
  iterator end() { return array + M * N; } 
};

#endif
