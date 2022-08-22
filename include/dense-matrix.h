#ifndef _DENSE_MATRIX_H // leading underscore to avoid naming conflicts 
#define _DENSE_MATRIX_H

#include <iostream> 

// heap-allocated matrix stored as 1D Row-Major i*N+j 
template <typename T>
class dense_Matrix {
public:
  //  moved definitions to this file to avoid explicit instantiation  
  
  // constructor
  dense_Matrix(int rows, int cols) : m_rows(rows), m_cols(cols), array(new T[m_rows*m_cols]) {}
  
  // copy constructor
  dense_Matrix<T>(const dense_Matrix<T> &dM){ 
    m_rows = dM.Rows;
    m_cols = dM.Columns;
    array  = new T[m_rows*m_cols];
    for (int x(0); x < m_rows*m_cols; x++) {
        array[x] = dM.array[x];
    }
    std::cout << "\nCopy Constructor Used\n"; 
}

  // move constructor 
  dense_Matrix<T>(dense_Matrix<T> &&dM) noexcept{ 
     this->m_rows = dM.m_rows;
     this->m_cols = dM.m_cols;
     this->array  = dM.array;

     //Releases resources of Dense Matrix parameter
     dM.Data = nullptr;
     dM.Rows = 0;
     dM.Columns = 0;
	 std::cout << "\nMove Constructor Used\n"; 
} 
      
  // destructor
  virtual ~dense_Matrix() { delete[] array; }
  
  // overload operator() for data at i,j access 
  T &operator()(int i, int j) {return array[i*m_cols+j]; } // row major
  T operator()(int i, int j) const {return array[i*m_cols+j]; } // row major [R/O]
  
  // explicit M,N accessor 
  int Rows() const {return m_rows;}
  int Cols() const {return m_cols;}
  
  // currently defined in .cpp 
  // Copy assignment  
  dense_Matrix<T>& operator=(const dense_Matrix<T>& rhs){
     if (&rhs == this) {
        return *this;
     }

	//Checks for dimensinal mismatch
	if (!((this->m_rows == rhs.Rows && this->Columns == &rhs.m_cols))) {
		delete[] array;
		this->m_rows = rhs.m_rows;
		this->m_cols = rhs.m_cols;
		array = new T[m_rows*m_cols];
	}

    //Populates this->Data with data from parameter
	for (int iElement(0); iElement < (m_rows*m_cols); iElement++) {
			array[iElement] = rhs.array[iElement];
		}
		return *this;
	} 
  
  // Move assignment 
  dense_Matrix<T>& operator=(dense_Matrix<T>&& rhs) noexcept{ 
     if (this != &rhs) {
                delete[] array; //Ensures Data is clear before proceeding
                array = rhs.array;
                m_rows = rhs.Rows;
                m_cols = rhs.Columns;

                //Releases resources of Dense Matrix parameter
                rhs.array = nullptr;
                rhs.m_rows = 0;
                rhs.m_cols = 0;
            }
			std::cout << "\nMove Assignment\n";  
            return *this;
     };

// print matrix 
void Print(){
	std::cout << (*this).Rows() << " Rows " << (*this).Cols() << " Columns\n"; 
    if ((*this).Rows() < 25 && (*this).Cols() < 25){ 
    	for (int i = 0; i < (*this).Rows(); ++i){
			for (int j = 0; j < (*this).Cols(); ++j){
      			std::cout << "  " <<  (*this)(i, j) << " ";
    		}
    		std::cout << ("\n");
  		}
  	  std::cout << ("\n"); 
	} else {
		std::cout << "Printing first 25 values\n"; 
		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
      			std::cout << "      " <<  (*this)(i, j) << " ";
    		}
    		std::cout << ("\n");
  		}
  		std::cout << ("\n"); 
	}
} 



  
  // void Resize(int Mprime, int Nprime);
  // void Print(); // show data
  // special init methods 
  // void init_diag(const T& fill);           // non-zero values on diagonal  
  // iterator 
  // using iterator = T*;                     // use pointers to replicate an iterator  
  // iterator begin() { return array; }
  // iterator end() { return array + m_rows * m_cols; } 

private:
  int m_rows, m_cols;
  T* array;
};

#endif
