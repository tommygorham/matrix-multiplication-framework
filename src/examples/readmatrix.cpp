// test2: read in matrix from txt file 
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
    dense_Matrix<float> A(N,N); 
    
	// read and fill 
	for (int i = 0; i < A.Rows(); ++i) {
		for (int j = 0; j < A.Cols(); ++j) {
          file_a >> A(i, j);
        }
    }
	cout << "size of matrices: " << N << endl;  
	file_a.close(); // done with input 
    
	return 0; 
}
