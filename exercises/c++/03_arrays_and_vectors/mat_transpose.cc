#include <iostream>
#include <string>
#include <array>
#include <sstream>


using namespace std;


template<typename T  >
void transpose_matrix( T& mat, size_t rows, size_t cols  );

template<typename T  >
void print_matrix( T& mat, size_t rows, size_t cols  );



int main () {
	
	constexpr size_t M{6}, N{10};

	array<double, M*N> matrix;
	
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
	
	T tmp{};
	for (size_t i{0}; i<cols;++i) {
		for (size_t j{0};j<rows;++j) {
			tmp[rows*i + j]=  mat[cols*j + i] ;
		}

	}
	swap(tmp,mat);
	
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