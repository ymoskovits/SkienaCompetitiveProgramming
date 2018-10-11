#include <iostream>
#include <fstream>
using namespace std;

int getCycleLength(int x, int arr[]);

int findMaxCycleLength(int a, int b, int arr[]);

int main(){
	int start = 0, end = 0;
	int memo[999999] = {0};
	// ifstream in("input.txt");
	// ofstream out("output.txt");
	while (cin >> start){
		cin >> end;
		cout << start << " " << end << " ";
		if(start > end){
			int temp = start;
			start = end;
			end = temp;
		}
		cout << findMaxCycleLength(start, end, memo) << endl;
	}

	return 0;
}



int getCycleLength(int i, int arr[]){

	//If i is too big, dont try to access the memo.
	if (i > 999998){
		// Dont remember what this was about.
		if (i == 1){
			return 1;
		}

		// Recursively call the function, passing in the param for next even or odd element in sequence.
		if(i % 2 == 0){
			return 1 + getCycleLength(i / 2 , arr);
		}
		else{
			return 1 + getCycleLength(3 * i + 1, arr);
		}
	}

	if (i == 1){
		return 1;
	}

	// If already calculated, dont count up how many steps are left, just return what we know.
	if (arr[i] != 0){
		return arr[i];
	}

	// Compute and memoize:
	if (i % 2 == 0){
		arr[i] = 1 + getCycleLength(i / 2, arr);
	}
	else{
		arr[i] = 1 + getCycleLength((3 * i) + 1, arr);
	}
	
	return arr[i];

}


int findMaxCycleLength(int a, int b, int arr[]){
	int maxLen = 0, thisLen = 0;
	for (int i = a; i <= b; ++i){
		thisLen = getCycleLength(i, arr);
		if (thisLen > maxLen){
			maxLen = thisLen;
		}
	}
	return maxLen;

}

