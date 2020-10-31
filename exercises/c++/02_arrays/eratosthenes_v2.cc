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
		std::cout << 2*i + 3 << " : " << array[i] <<std::endl;	
	}
	
}

int main() {
	
	cout << "Sieve of Eratosthenes Algorithm." << endl;
	
	uint64_t N;

	N = input_control<uint64_t>("Please enter the integer upper bound on the prime numbers.");

	int len = N/2 + N%2-1;
	cout << len << endl;
	
	//allocate an array of flags
	bool* flags{new bool[ len]};
	
	//the array of flags will contain only the odd numbers greater than 2
	//because all even numbers except 2 are surely not primes
	//the algorithm therefore is not applied to 2 for efficiency
	
	//the flags array is initialised to all zeroes by default
	//zeroes will mark prime numbers at the end of the iterations
	
	
	
	
	//we start from an ODD number*cur_prime*. If it's prime, we run an inner loop which flags all the multiples if *cur_prime*
	// (not including *cur_prime* itself) until they exceed N. The flagging starts actually from *cur_prime^2* (i.e. the *cur_prime*-th multiple) 
	//because all the numbers between *cur_prime* and *cur_prime^2* are either prime or have already been flagged. 
	//we then increment *cur_prime*  until we hit another unflagged ODD number, which will be the next prime
	//when *cur_prime^2* is greater or equal to N we trigger the break, as running through the other numbers is pointless
	
	//bool exit=false;
	//while (!(exit)) {
	//	if (flags[cur_prime] == 0) {
	//		//found a prime
	//		prime_mult = cur_prime*cur_prime;
	//		if (prime_mult>=N) {
	//			exit=true;
	//		} 
	//		else {
	//			do {
	//				int idx = std::floor(N/2) ;
	//				cout << idx << endl;
	//				flags[ idx ] =1;
	//				prime_mult = prime_mult + cur_prime;
	//			} while (prime_mult<=N);
	//		}
	//	}
	//	cur_prime = cur_prime + 2;	
	//} 
	
	
	bool exit=false;
	uint64_t odd_idx = 0;
	uint64_t odd_mult_idx;
	
	while (!(exit)) {
		if (flags[odd_idx] == 0) {
			//this is the index of the square of the odd number corresponding to odd_idx
			odd_mult_idx = 2*odd_idx*(odd_idx + 3) + 3;
			
			if (odd_mult_idx>=len) {
				exit=true;
			} 
			else {
				do {
					flags[ odd_mult_idx ] =1;
					odd_mult_idx = odd_mult_idx + 4*odd_idx + 6;
				} while (odd_mult_idx<len);
			}
		}
		odd_idx = odd_idx + 1;	
	} 
	
	print_array<bool, uint64_t> (flags, len);
	
	//as mentioned, the number 2 is excluded so we hard-code its printout
	std::cout << "2" <<std::endl;	
	//loop to print the odd numbers starting from 3, if unflagged
	for (uint64_t i{0}; i<len; ++i) {
		if ( flags[i] == 0 ) {
			std::cout << 2*i + 3 <<std::endl;	
		}
	}

	delete[] flags;
	
}