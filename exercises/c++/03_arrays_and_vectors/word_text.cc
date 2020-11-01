#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdbool>

using namespace std;

template <typename T, typename T2>
void add_uniq( std::vector <T>& words, std::vector <T2>& wordcount, string new_wrd);

template <typename T, typename T2>
void print_wordvec( const std::vector <T>& w, const std::vector <T2>& wc ) ;

int main(int argc, char ** argv ) {
	
	//define an array of all the possible delimiters between words
	char delims[]{' ',',',';','.',':','\'','"','?','!'};
	
	vector<string> word_vec{};
	vector<long unsigned int> word_count{};
	
	string line {""};
	while(std::getline(std::cin,line))
	{
		string word;
		for (auto x : line) {
			bool isdelim{false};
			
			for (auto d : delims) {
				if (x==d) {
					isdelim=true;
					break;
				}
			}
			if (isdelim) {
				if (word.compare("")!=0 )
					add_uniq(word_vec,word_count,word);
				word = "";
			} else {
				word = word + x;	
			}
		}
		
		
	}

	print_wordvec(word_vec,word_count);
	
	word_vec.clear();
	word_count.clear();

}


template <typename T, typename T2>
void add_uniq( std::vector <T>& words, std::vector <T2>& wordcount, string new_wrd) {

	bool isnew{true};
	auto i=0u;
	for (auto& w : words) {
		if (new_wrd.compare(w)==0) {
			wordcount[i]+=1;
			isnew=false;
			break;
		}
		++i;
	}
			
	if (isnew) {
		words.push_back(new_wrd);	
		wordcount.push_back(1);	
	}
	
	
}
			
template <typename T, typename T2>
void print_wordvec( const std::vector <T>& w, const std::vector <T2>& wc ) {
	
	for (auto i=0u; i< w.size();++i) {
		cout << w[i] << " : " << wc[i] << endl;
	}
	
}