#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T >
void calc_mean_median( const std::vector <T>& v, double* mean, double* median);

template <typename T >
void print_vector( const std::vector <T>& v);


int main( int argc, char ** argv ) {
	//handle filename argument
	if (argc <2) {
		cerr << "Please run the program specifying the numeric file to open," << endl;
		exit(1);
	}
	string filename{argv[1]};
	
	
	fstream fs;
	fs.open(filename, fstream::in);
	if (!fs.is_open()) {
		cerr << "Error opening the file." << endl;
		exit(1);
	}
	
	//load values into array and sort
	vector<double> vec;
    double a;
    while (fs >> a)
    {
        vec.push_back(a);
    }
	fs.close();
		
	sort( vec.begin() , vec.end() ) ;

	//check
	print_vector(vec);
	
	//calculate mean and median
	//pass the median and mean by pointer
	double mean{0}, median{0};
	calc_mean_median(vec, &mean, &median);
	
	printf("Mean of the values : %f\n",mean);
	printf("Median of the values : %f\n",median);
	
	vec.clear();
	return 0;
}

template <typename T >
void calc_mean_median( const std::vector <T>& v, double* mean, double* median) {
	
	unsigned long int len{0};
	double M{0}, MM{0};
	for (const auto& x : v) {
		M+=x;
		++len;
	}
	M=M/len;
	
	//if len (# of elems) is even, the median 
	//is the average value of v[elem/2 - 1] and v[elem/2]
	//if it's odd, it's the element v[floor(len/2)]
	
	unsigned long int x;
	x = std::floor(len/2);
	if (len%2==0) {
		MM = ( v[x] + v[x-1] ) /2;
	} else {
		MM = v[x];	
	}
	
	
	
	*mean = M;
	*median = MM;
}

template <typename T >
void print_vector( const std::vector <T>& v) {
	
	unsigned long int i{0};
	for (const auto& x : v) {
		printf("Elem %lu : %f\n",i,x);
		++i;
	}
	
}