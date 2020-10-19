#include <iostream>
#include <string>
#include <cstdbool>

double converter () {
	double input;
	double factor{0};
	std::string unit {""};
	
	bool valid{false};
	
	while (!(valid)) {
		std::cout << "Enter a value and its unit of measure, separated by spaces." << std:endl;
		
		std::cin >> input >> unit
			
		if (!std::cin) {
			std::cout << "Invalid input. Please retry." << std:endl;
		} else {
		
			switch(unit) {
			  case m:
				factor = 1;
				valid=true;
				break;
			  case f:

				break;
			  default:
				std::cout << "Unrecognised unit. Please retry." << std:endl;
			}
			
		}
		
		if (!(valid)) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
		
	}
	
	
}

int main () {

	double len{0};
	
	std::cout << "Welcome to Length Unit Converter." << std:endl;
	
	len= converter()
	
	std::cout << "Result: " << len >> " m" << std:endl;
}