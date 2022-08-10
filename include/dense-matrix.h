#ifndef _DENSE_MATRIX_H
#define _DENSE_MATRIX_H

// heap-allocated matrix stored as 1D Row-Major i*N+j 
template <typename T>
class dense_Matrix {
public:
// defined in this file 
  // constructor
  dense_Matrix(int rows, int cols) : m_rows(rows), m_cols(cols), array(new T[m_rows*m_cols]) {}
  // copy constructor: dense_Matrix<T>(const dense_Matrix<T> &DM); 

  // destructor
  virtual ~dense_Matrix() {delete[] array;}
  
  // overload operator()
  T &operator()(int i, int j) {return array[i*m_cols+j]; } // row major
  T operator()(int i, int j) const {return array[i*m_cols+j]; } // row major [R/O]

  // explicit accessor 
  int Rows() const {return m_rows;}
  int Cols() const {return m_cols;}

// defined in .cpp 
  // overload assignment for copy 
  dense_Matrix<T> &operator=(const dense_Matrix<T> &rhs); 
  void Resize(int Mprime, int Nprime);
  void Print(); // show data
  void init_with_const_val(const T& fill); // e.g., init all 2's 
  void init_diag(const T& fill);           // non-zero values on diagonal  
  using iterator = T*;                     // use pointers to replicate an iterator  
  iterator begin() { return array; }
  iterator end() { return array + m_rows * m_cols; } 

private:
  int m_rows, m_cols;
  T* array;
};

#endif
