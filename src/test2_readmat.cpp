// test 2: read in matrix from txt file 
#include <iostream> 
using std::cout; 
using std::endl; 
#include <fstream> 
using std::ifstream; 
#include <string> 
using std::string; 
#include <iomanip> 
using std::setw;
#include <chrono> 
#include "dense-matrix.h" 

template <typename T> 
void print(dense_Matrix<T> &DM, std::string_view name)
{ 
	cout << "\nMatrix " << name << "\n"; 
	for(int i = 0; i < DM.Rows(); ++i)
    {		
		for(int j=0; j < DM.Cols(); ++j) 
		{ 
			cout << setw(4) << DM(i,j); 
		}
    	cout << "\n"; 
	} 
		cout << "\n"; 
} 

int main(int argc, char* argv[])
{
    // check input     
	if (argc != 2) { 
		// We print argv[0] assuming it is the program name
    	cout << "usage: " << argv[0]
             << " Requires 2 inputs at runtime: <./run> <INPUT-A.txt>\n";
		return -1; 
	}

    // get input 
    ifstream file_a(argv[1]);
    std::string firstline_a;
    getline(file_a, firstline_a); 
    int N = std::stoi(firstline_a);
    
	// declare  matrices with size 	
    dense_Matrix<float> A(N,N); 
	dense_Matrix<float> B(N,N);
	dense_Matrix<float> C(N,N);
    
	// read and fill 
	for (int i = 0; i < A.Rows(); ++i) {
		for (int j = 0; j < A.Cols(); ++j) {
          file_a >> A(i, j);
		 B(i,j) = i; 
        }
    }

    // ensure C is zeroed out 
	for(int i = 0; i < B.Rows(); ++i) 
	{ 
		for(int j = 0; j < B.Cols(); ++j) 
		{ 

			C(i,j) = 2.0; 
		}
	}



	cout << "size of matrices: " << N << endl;  
	file_a.close(); // done with input 
    
    // multiply 
	auto start = std::chrono::high_resolution_clock::now(); 
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j) 
	    {
			float temp = 0.0 ; 
			for(int k = 0; k < N; ++k) 
			{ 
				temp += A(i,k) * B(k,j); 
		    }  
			C(i,j) = temp; 
		}
	}
    auto end = std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double, std::milli> t = end-start;  
	cout << "\nproduct took: " << t.count() << "milliseconds\n"; 

    if(N < 50)
	{ 
		print(A, "A"); 
		print(B, "B"); 
        print(C, "C"); 
	} 
    
	return 0; 
}
