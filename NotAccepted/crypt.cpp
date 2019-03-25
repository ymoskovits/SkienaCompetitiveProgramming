/********************************
I wanted to use backtracking recursifvely but I realized that it would result in a tall stack.
Once I would get a solution I would have built a stack the size of the number of words to fill in.
I would want to terminate that recursion but using the exit statement would get me out of the main also.
If there are mulitple encoded lines I wouldnt know how to get out of all the recursive calls but keep main running.
A possible fix would be to return a bool from the calls and if its true then don't go on because we found a solution.
**********************************/

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <iterator>

using namespace std;

string* read_dict(int size);

int dict_size;
string *dict_arr;

int main(){
	
	vector<string> msg_vec;
	string word;
	string line;
	string token;
	set<string> msg_set;
	string *msg_arr;
	char mapping[256];
	int* word_match;
	int col;
	int msg_arr_size;

	//Get inupts.
	cin >> dict_size;
	dict_arr = read_dict(dict_size);
	getline(cin, line);

	//Solve for each message.
	while(!cin.eof()){
		//Clear the containers of message data.
		msg_vec.clear();
		msg_set.clear();
		for(int i = 'a'; i <= 'z'; ++i){
			mapping[i] = '*';
		}
		
		//Tokenize the message to decode.
		getline(cin, line);
		stringstream msg_stream(line);
		while(getline(msg_stream, token, ' ')){
			msg_vec.push_back(token);
		}

		//Start decoding proceess. Put each encoded word into a set to eliminate redundanices.
		for(int i = 0; i < msg_vec.size(); ++i){
			msg_set.insert(msg_vec[i]);
		}

		/***************************
		DEFINE "word_match[i] = j" AS:
			Elem i from the msg_arr was arived at by encoding word j in the dict_arr.
		****************************/

		msg_arr = new string[msg_set.size()]; // To hold the list of words in the message, this time with no redundancies.
		word_match = new int[msg_set.size()];

		int itr_counter = 0;

		for(set<string>::iterator itr = msg_set.begin(); itr != msg_set.end(); ++itr){
			msg_arr[itr_counter] = *itr;
			itr_counter++;
		}
		msg_arr_size = msg_set.size();


		//Start backtracking.
		col = 0;
		while(col < msg_arr_size){
			if(from_backtrack){
				mapping[col] = -1;
				col--;
				//Clear the map and refil only up to the point that we've confirmed as valid.
				for(int i = 'a'; i <= 'z'; ++i){
					mapping[i] = '*';
				}
				for(int i = 0; i <= col; ++i){
					for(int j = 0; j < mapping[i].length(); ++j){

					}
				}
			}
			else{
				col++;
			}
		}


	
		delete[] msg_arr;

	}


	














	delete[] dict_arr;

	return 0;
}


string* read_dict(int size){
	string word;
	string *dict = new string[size];
	for(int i = 0; i < size; ++i){
		cin >> word;
		dict[i] = word;
	}
	return dict;
}


// bool good_config(int *word_match, int up_to, char *mapping){


// }


// bool next_match(int *word_match, char *mapping, string *msg_arr, int cur_crypt, int words_to_match){
// 	if(cur_crypt == words_to_decrypt){
// 		print_solution();
// 		return true;
// 	}

	/********** 
	In order for a word to be a good match to a certain crypt:
		All of its letters must be either empty or already correct.
		The letters to which you're trying to convert must not be being used anywhere else.
	************/


// 	for(int word = 0; word < dict_size; ++word){
// 		//check the length of the word frist
// 		if(good_config(word_match, cur_crypt, .....)){
// 			edit_mapping();
// 			next_match(word_match, cur_crypt + 1, mapping, )
// 		}
// 	}
// }


//TODO:
/*********
print_solution()
edit_mapping()
good_config()
**********/




























