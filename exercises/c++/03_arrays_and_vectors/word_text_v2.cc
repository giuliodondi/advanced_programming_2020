#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
#include<vector>

using namespace std;



int main(int argc, char ** argv ) {
	
	//handle filename argument
	if (argc <2) {
		cerr << "Please run the program specifying the text file to open." << endl;
		exit(1);
	}
	string filename{argv[1]};

	fstream fs;
	fs.open(filename, fstream::in);
	if (!fs.is_open()) {
		cerr << "Error opening the file." << endl;
		exit(1);
	}
	
	string wrd;
	vector<string> words;
	
	while(fs >> wrd)
	{
		cout<< wrd << '\n';
	}
	
}