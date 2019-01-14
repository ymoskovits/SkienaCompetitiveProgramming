#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	
	int seq_len, elem, diff;
	vector<int> seq;
	bool *diff_tracker, jolly;

	//while there is still another set.
	while (cin >> seq_len){

		//Assume it's jolly until proven guilty.
		jolly = true;
		seq.clear();


		//Array to keep track of which differences we've encountered.
		diff_tracker = new bool[seq_len];
		for (int i = 0; i < seq_len; ++i){
			diff_tracker[i] = false;
		}

		//Get all the elements of the sequence on that input line.
		for(int i = 0; i < seq_len; ++i){
			cin >> elem;
			seq.push_back(elem);
		}

		//Get the difference between consecutive elements and record which differences were found.
		for (int i = 0; i < seq_len - 1; ++i){
			diff = abs(seq[i] - seq[i + 1]);
			if(diff >= seq_len){
				continue;
			}
			diff_tracker[diff] = true;
		}

		//Check if there are any missing differences.
		for(int i = 1; i < seq_len; ++i){
			if(diff_tracker[i] == false){
				jolly = false;
			}
		}

		if(jolly){
			cout << "Jolly" << endl;
		}
		else{
			cout << "Not jolly" << endl;
		}

		delete[] diff_tracker;
	}

	return 0;
}