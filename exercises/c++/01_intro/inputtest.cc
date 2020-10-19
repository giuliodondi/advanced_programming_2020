#include <iostream>
#include <cstdbool>

int get_int() {
	
	
	int input{0};
	
	while (true) {
		std::cout << "Please enter an integer number:" << std::endl;
		
		
		
		
		if (!(std::cin >> input )) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
		} else {
			break;	
		}
	} 
	
	
	//std::cout << "Please enter an integer number:" << std::endl;
	//while (!(std::cin >> input )) {
	//	std::cin.clear();
	//	std::cin.ignore();
	//	std::cout << "Please enter an integer number:" << std::endl;
	//}
	
	
	return input;

}

double get_double() {
	std::cin.clear();
	std::cin.ignore(100,'\n');
		
	double input;
	while (true) {
		std::cout << "Please enter a real number:" << std::endl;
		if (!(std::cin >> input )) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
			
		} else {
			break;	
		}
	} 
	
	
	return input;
	
	
}



int main() {
	
	int a = get_int();
	std::cout << a << std::endl;
	double b = get_double() ;
	std::cout << b << std::endl;
	
}