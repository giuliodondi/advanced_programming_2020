#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;


template<typename T  >
void transpose_matrix( T& mat, size_t rows, size_t cols  );

template<typename T  >
void print_matrix( T& mat, size_t rows, size_t cols  );



int main (int argc, char ** argv) {
	if (argc != 3) {
		cerr << "Please run the program with only two integer arguments, rows and columns of the matrix." << endl;
		exit(1);
	}
	

	std::size_t M{0}, N{0};
	{
		std::istringstream rows{argv[1]};
 		rows >> M;
		std::istringstream cols{argv[2]};
 		cols >> N;
	}
	
	
	vector<double> matrix(M*N,0);
	
	//initialise the matrix, increasing numbers
	for (size_t i{0};i<M*N;++i) {
			matrix[i] = i;
	}
	
	cout << "Initial matrix:" << endl;
	print_matrix(matrix,M,N);
	
	transpose_matrix(matrix,M,N);
	
	cout << "Transposed matrix:" << endl;
	print_matrix(matrix,N,M);
	
	return 0;
}

template<typename T  >
void transpose_matrix( T& mat, size_t rows, size_t cols  ) {
	
	vector<double> tmp(rows*cols,0);
	
	for (size_t i{0}; i<cols;++i) {
		for (size_t j{0};j<rows;++j) {
			tmp[rows*i + j]=  mat[cols*j + i] ;
		}

	}
	swap(tmp,mat);
	tmp.clear();
	
}

template<typename T  >
void print_matrix( T& mat, size_t rows, size_t cols  ) {

	for (size_t i{0}; i<rows;++i) {
		cout << "|";
		for (size_t j{0};j<cols;++j) {
			cout << " " << mat[cols*i + j];
			
		}
		cout << "|" << endl;
	}
	
}