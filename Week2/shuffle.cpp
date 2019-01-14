/******************
	We will store the cards as ints representing their initial position in the deck.
	Keep 2 arrays to move the cards back and forth from for each shuffle.
*******************/

#include <iostream>
#include <vector>

using namespace std;

void print_deck(int *a);
int** read_in_shuffles(int num_of_shuffles);
vector<int> get_list_of_shuffles();

int main(){
	
	int cases, num_of_shuffles, new_pos, next_shuffle, shuffle_number;
	string line;

	int *a = new int[53];
	int *b = new int[53];
	int *temp_p;
	int *cur_shuffle_arr;
	int **shuffles_list;
	vector<int> shuffles_to_execute;

	cin >> cases;
	for (int set = 0; set < cases; ++set){
		cin >> num_of_shuffles;

		shuffles_list = read_in_shuffles(num_of_shuffles);

		//Initialize both arrays to a fresh deck.
		for(int i = 1; i <= 52; ++i){
			a[i] = i;
			b[i] = i;
		}

		//Get the list of observed shuffles and simulate them.
		shuffles_to_execute = get_list_of_shuffles();		
		for(int i = 0; i < shuffles_to_execute.size(); ++i){
			shuffle_number = shuffles_to_execute[i];
			cur_shuffle_arr = shuffles_list[shuffle_number];
			for(int new_pos = 1; new_pos <= 52; ++new_pos){
				b[new_pos] = a[cur_shuffle_arr[new_pos]];
			}

			//Make "a" point to the new array.
			temp_p = b;
			b = a;
			a = temp_p;
		}

		print_deck(a);
		if(set != cases-1){
			cout << endl;
		}

		for (int i = 0; i < num_of_shuffles; ++i){
			delete[] shuffles_list[i];
		}
		delete[] shuffles_list;
	}


	return 0;
}




int** read_in_shuffles(int num_of_shuffles){
	int next;
	int **list_of_shuffles = new int*[num_of_shuffles];
	for(int i = 0; i < num_of_shuffles; ++i){
		list_of_shuffles[i] = new int[53];
	}
	//Fill in each shuffle.
	for(int shuffle = 0; shuffle < num_of_shuffles; ++shuffle){
		for(int position = 1; position <= 52; ++position){
			cin >> next;
			list_of_shuffles[shuffle][position] = next;
		}
	}
	return list_of_shuffles;
}


void print_deck(int *a){
	int card, num, suit;

	for(int i = 1; i <= 52; ++i){
		card = a[i];
		num = (card - 1) % 13;
		suit = (card - 1) / 13;
		switch(num){
			case 9:
				cout << "Jack of ";
				break;
			case 10: 
				cout << "Queen of ";
				break;
			case 11: 
				cout << "King of ";
				break;
			case 12: 
				cout << "Ace of ";
				break;
			default: 
				cout << num + 2 << " of ";
				break;
		}

		switch(suit){
			case 0:
				cout << "Clubs" << endl;
				break;
			case 1:
				cout << "Diamonds" << endl;
				break;
			case 2:
				cout << "Hearts" << endl;
				break;
			case 3:
				cout << "Spades" << endl;
				break;
			default:
				cout << "ERROR\n\n\nERROR\n\n\nERROR\n\n\n" << endl;
				break;
		}
	}
}


vector<int> get_list_of_shuffles(){
	string line;
	int shuf;
	vector<int> v;
	getline(cin, line);
	getline(cin, line);

	while(line != ""){
		shuf = stoi(line);
		v.push_back(shuf-1);
		if(cin.eof()){
			return v;
		}
		else{
			getline(cin, line);
		}
	}
	return v;
}




