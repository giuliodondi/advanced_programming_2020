#include <iostream>
#include<string>

int main() {

	std::string line {""};
	std::string line2 {""};
	unsigned int count {1};
	while(std::getline(std::cin,line))
	{
		
		if (line2 == line){
			++count; 
		}
		else if (line2 != "") {
			std::cout << count << " " << line2  << std::endl;
			count=1;
		}
		
		line2 = line;
	}

}