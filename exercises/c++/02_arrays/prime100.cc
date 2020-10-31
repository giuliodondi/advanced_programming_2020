#include <iostream>
#include <cmath>
#include <cstdbool>

//for every number between 2 and n-1, test if the remainder is zero
//skip 1 and n because it would obviously work
//if the test fails at any point, set a flag to false and break out
//only if every test passes return true
bool primetest( uint64_t n) {
	bool out = true;	
	for (uint64_t i=2; i<=(n - 1); ++i) {
		if (!(n%i)) {
			out=false;
			break;
		}
	}
	return out;
}

template<typename T,U>
void print_array(T* array, U len) {
	
	
	for (std::size_t i{0}; i<=len; ++i) {
		std::cout << array[i] <<std::endl;	
	}
	
}



int main() {
	
	unsigned long int N = 100;	
	
	//allocate the entire array right away as N is known
	//(hard-coded at 100 for the time being, possibly let the user enter it)
	
	//allocate the array in the heap 
	uint64_t *prime_arr(new uint64_t[N]);
	
	prime_arr[0]=2;
	uint64_t cur_prime = 2;
	bool isprime = false;
	
	for (std::size_t i{1}; i<=N; ++i) {
		while (!(isprime)) {
			cur_prime = cur_prime + 1;
			isprime = primetest(cur_prime);
		}
		prime_arr[i] = cur_prime;
		isprime = false;
	}
	
	std::cout << "Printing the first " << N << " prime numbers." << std::endl;
	print_array<uint64_t, typein(N)>( (prime_arr, N);
	
	//std::cout << "The " << N << "-th prime number is : " << prime_arr[N-1] << std::endl;
	
	delete[] prime_arr;
}