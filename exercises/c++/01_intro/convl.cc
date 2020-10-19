#include <iostream>
#include <string>
#include <cstdbool>

std::string converter () {
	double input;
	double factor{0};
	std::string unit {""};
	
	bool valid{false};
	
	while (!(valid)) {
		std::cout << "Enter a value and its unit of measure, separated by spaces." << std::endl;
		
		std::cin >> input >> unit;
		
			
		if (!std::cin) {
			std::cout << "\n" <<   "Invalid input. Please retry." << std::endl;
		} else {
			
			//handle unit formatting
			unsigned int unit_id{0};
			if ( (unit.compare("m") == 0) || (unit.compare("metres")==0) || (unit.compare("Metres")==0) || (unit.compare("meters")==0) || (unit.compare("Meters")==0) ) {
				unit_id=1;	
			}
			else if ( (unit.compare("ft") == 0) || (unit.compare("feet")==0) || (unit.compare("Feet")==0)  ) {
				unit_id=2;	
			}
			else if ( (unit.compare("in") == 0) || (unit.compare("inches")==0) || (unit.compare("Inches")==0) ) {
				unit_id=3;	
			}
		
			switch(unit_id) {
				case 1:
					factor = 1;
					valid=true;
					break;
				case 2:
					factor = 0.3048;
					valid=true;
					break;
				case 3:
					factor = 0.0254;
					valid=true;
					break;
				default:
					std::cout << "\n" <<  "Unrecognised unit. Please retry." << std::endl;
			}
			
		}
		
		if (!(valid)) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
		
	}
	
	std::string output = std::to_string(input*factor) + " m";
	return output;
	
}

int main () {

	double len{0};
	
	std::cout << "Welcome to Length Unit Converter." << std::endl;

	
	std::string result = converter();
	
	std::cout << "Result: " << result<< std::endl;
}