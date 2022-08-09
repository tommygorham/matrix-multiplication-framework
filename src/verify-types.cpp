#include "dense-matrix.h"
#include "verify-types.h"

#include <iostream>
#include <typeinfo> 

template <typename T>
int verify_Types(const dense_Matrix<T> &A, const dense_Matrix<T> &B) {
	auto v1 = A(1,1); 
	auto v2 = B(1,1); 
    if (typeid(v1).name() != typeid(float).name() ||   
	   (typeid(v2).name() != typeid(float).name()))  
    {
		std::cout << "verifyTypes(): Invalid types in matrix\n" << std::endl;
        return -1;
    } 
	return 0; 
}

template int verify_Types(const dense_Matrix<float> &A, const dense_Matrix<float> &B);
