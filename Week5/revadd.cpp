#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

bool palindrome(long long num);


int main(){

	long long num_of_sets, num, rev_num, count = 0;
	string str, rev_str;
	cin >> num_of_sets;
	for(int set = 0; set < num_of_sets; ++set){
		count = 0;
		cin >> num;
		do{
			stringstream stream;
			stream << num;
			stream >> str;
			rev_str = str;
			reverse(rev_str.begin(), rev_str.end());

			stream.clear();
			stream << str;
			num = 0;
			stream >> num;

			stream.clear();
			stream << rev_str;
			stream >> rev_num;
			num = num + rev_num;
			count++;
		}while(!palindrome(num) && count < 200);
		cout << count << " " << num << endl;
	}

	
	return 0;
}

bool palindrome(long long num){
	string str = to_string(num);
	string rev = str;
	reverse(rev.begin(), rev.end());
	return str == rev;
}