/*
	We will take advantage of a recursive pattern:
		The list of 1s starting at index 1 (not 0 based indexing) will be the base case.
		For all others, to figure out which index a list of a certain number starts we can use:
			the previous numbers starting place + f(the previous number) = This numbers starting place;
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Range{
	public:
		int number;
		int beg;

	Range(){
		number = 0;
		beg = 0;
	}
	Range(int n, int b){
		number = n;
		beg = b;
	}
};

vector<Range*> ranges;

int fon(int n){
	//Do a binary search on the different ranges to find the range that n is in.
	int l = 0; int r = ranges.size() - 1; int m = r / 2;
	while(true){
		if(ranges[m]->beg > n){
			r = m - 1;
			m = (r-l) / 2 + l;
		}
		else if(ranges[m]->beg < n && ranges[m + 1]->beg <= n){
			l = m + 1;
			m = (r-l) / 2 + l;
		}
		else{
			return ranges[m]->number;
		}
	}

	return ranges[ranges.size() - 1]->number;
}


int main(){
	int n = 2;
	Range* temp = new Range();
	temp->number = 1;
	temp->beg = 1;
	ranges.push_back(temp);

	//Fill in the vector with all the ranges.
	while(n <= 2000000000){
		int temp_num = ranges.back()->number + 1;
		// cout << "FON OF " << temp_num -1 << ":\t" << fon(temp_num-1) << endl;
		int temp_beg = fon(temp_num-1) + ranges.back()->beg;		//cout << temp_num << "     " << temp_beg << endl;

		temp = new Range(temp_num, temp_beg);
		ranges.push_back(temp);
		n = ranges.back()->beg;
	}

	// for(Range* i : ranges){
	// 	cout << "BEG: " << i->beg << endl << "NUM: " << i->number << endl << endl;
	// }




	//Start getting input.
	int input;
	while(cin >> input){
		if(input == 0){
			break;
		}
		cout << fon(input) << endl;
	}



	return 0;
}



