#include <iostream>
#include <cstdbool>


template<typename T>
T* array_init( const int len);

template<typename T>
void print_array(T* array, const int len);


int main() {
	
	long unsigned int len{0};
	
	std::cout << "\n" << "Enter the length of the array." << std::endl;
	while (true) {
		std::cout << "Please enter an integer number:" << std::endl;
		if (!(std::cin >> len )) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
		} else {
			break;	
		}
	} 

	char typ;
	std::cout << "\n" << "Please specify the array data type.\n"
	 << "Write 'i' for integer, 'li' for long integer, 'f' for float, 'd' for double float."	<< std::endl;
	
	bool valid=false;
	while(!(valid)) {
		valid=true;
		std::cin >> typ;
		switch(typ) {
			case 'i': {
				int* arrint = array_init<int>(len);
				print_array<int>(arrint,len);
				delete[] arrint;
				break;
			}
			case 'd': {
				double* arrdbl = array_init<double>(len);
				print_array<double>(arrdbl,len);
				delete[] arrdbl;
				break;
			}
			default:
				valid=false;
				std::cout  << "\n" << "Unrecognised type. Please retry." << std::endl;
		}
	}
	//print_array<decltype(*array)>(array);
	
	
	
}



template<typename T>
T* array_init( const int len) {

	T* arr(new T[len]);
	
	std::cout << "\n" << "Please enter "<< len << " numbers to populate the array.\n"
	 << "All elements should be of same type."	<< std::endl;

	T input;
	std::size_t i{0};
	while ( i < len) {
		
		if (!(std::cin >> input )) {
			std::cout << "Invalid input. Please retry.:" << std::endl;	
			std::cin.clear();
			std::cin.ignore(100,'\n');
		} else {
			arr[i] = input;
			++i;
		}
	}

	return arr;
	
}

template<typename T>
void print_array(T* array, const int len) {
	
	
	for (std::size_t i{len-1}; i<len; --i) {
		std::cout << "element " << i << " : " << array[i] <<std::endl;	
	}
	
}