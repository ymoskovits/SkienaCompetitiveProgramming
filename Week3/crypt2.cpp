#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
using namespace std;

int get_index_of_fox(vector<string>& encodings);
string convert_to_general_format(string input);
void print_decoded_string(char mapping[], string encoded_msg);

string fox_sentence = "the quick brown fox jumps over the lazy dog";


int main(){
	
	char map[256];
	int cases, index_of_fox;
	string line;
	cin >> cases;
	getline(cin, line);
	string fox_sentence_encoded;

	unordered_map<char, char> mapping;
	vector<string> list_of_encodings;

	getline(cin, line);

	for(int set = 0; set < cases; ++set){

		mapping.clear();
		list_of_encodings.clear();
		//Get input into vector.
		while(!cin.eof()){
			getline(cin, line);

			if(line == ""){
				break;
			}
			list_of_encodings.push_back(line);
		}
		index_of_fox = get_index_of_fox(list_of_encodings);
		if(index_of_fox == -1){
			cout << "No solution." << endl;
			if(set != cases-1){
				cout << endl;
			}
			continue;
		}
		fox_sentence_encoded = list_of_encodings[index_of_fox];

		//Create mapping.
		for(int letter = 0; letter < fox_sentence.size(); ++letter){
			// mapping[(char)letter] = 'a';
			map[fox_sentence_encoded[letter]] = fox_sentence[letter];
			
		}

		for(int encoding = 0; encoding < list_of_encodings.size(); ++encoding){
			print_decoded_string(map, list_of_encodings[encoding]);
		}
		cout << endl;
	}

	return 0;
}


int get_index_of_fox(vector<string>& encodings){
	vector<string> parsed_entry;
	string line, token;
	string generalized_fox_sentence = convert_to_general_format(fox_sentence);
	string generalized_entry;

	for(int entry = 0; entry < encodings.size(); ++entry){
		line = encodings[entry];
		generalized_entry = convert_to_general_format(line);
		if(generalized_entry == generalized_fox_sentence){
			return entry;
		}
	}
	return -1;
}

string convert_to_general_format(string input){
	string output = "";
	string next_char;
	queue<char> alphabet;
	// unordered_map<char, char> used;
	char used[256];
	for(int i = 0; i < 256; ++i){
		used[i] = '*';
	}
	for(char i = 'a'; i <= 'z'; ++i){
		alphabet.push(i);
	}

	for(int letter = 0; letter < input.size(); ++letter){
		//If you haven't seen this letter before, assign it to the next letter in the queue.
		if(input[letter] == ' '){
			output = output + " ";
			continue;
		}
		if(used[input[letter]] == '*'){
			next_char = alphabet.front();
			alphabet.pop();
			output = output + next_char;
			used[input[letter]] = next_char[0];
		}
		else{
			output = output + used[input[letter]];
		}
	}
	return output;

}

void print_decoded_string(char mapping[], string encoded_msg){
	for(int letter = 0; letter < encoded_msg.size(); ++letter){
		cout << mapping[encoded_msg[letter]];
	}
	cout << endl;
}



