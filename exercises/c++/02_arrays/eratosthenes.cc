#include <iostream>
#include <cmath>
#include <cstdbool>
#include <string>

using namespace std;

template < typename T>
T input_control(string msg) {
	T input;
	std::cout << msg << std::endl;
	while (true) {
		if (!(std::cin >> input )) {
			std::cout << "Invalid input. Please retry."<< std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
		} else {
			break;	
		}
	}
	return input;
	
}

template<typename T,typename U>
void print_array(T* array, U len) {
	
	for (std::size_t i{0}; i<len; ++i) {
		std::cout << array[i] <<std::endl;	
	}
	
}

int main() {
	
	cout << "Sieve of Eratosthenes Algorithm." << endl;
	
	uint64_t N;

	N = input_control<uint64_t>("Please enter the integer upper bound on the prime numbers.");

	
	int len = N - 2 + 1;
	
	//allocate an array of flags
	bool* flags{new bool[ len]};
	
	//the flags array is initialised to all zeroes by default
	//zeroes will mark prime numbers at the end of the iterations
	
	
	
	uint64_t cur_prime = 2;
	uint64_t prime_mult;
	
	//we have a variable containing the first prime number since it gets re-used over and over
	//we start from a number*cur_prime*. If it's prime, we run an inner loop which flags all the multiples if *cur_prime*
	// (not including *cur_prime* itself) until they exceed N. The flagging starts actually from *cur_prime^2* (i.e. the *cur_prime*-th multiple) 
	//because all the numbers between *cur_prime* and *cur_prime^2* are either prime or have already been flagged. 
	//we then increment *cur_prime* until we hit another unflagged number, which will be the next prime
	//when *cur_prime^2* is greater or equal to N we trigger the break, as running through the other numbers is pointless
	
	bool exit=false;
	while (!(exit)) {
		if (flags[cur_prime] == 0) {
			//found a prime
			prime_mult = cur_prime*cur_prime;
			if (prime_mult>=N) {
				exit=true;
			} 
			else {
				do {
					flags[prime_mult - 2] =1;
					prime_mult = prime_mult + cur_prime;
				} while (prime_mult<=N);
			}
		}
		cur_prime = cur_prime + 1;	
	} 
	
	//print_array<bool, uint64_t> (flags, len);
	
	for (uint64_t i{0}; i<len; ++i) {
		if ( flags[i] == 0 ) {
			std::cout << i + 2 <<std::endl;	
		}
	}

	delete[] flags;
	
}