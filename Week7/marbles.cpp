/*
General algo:
	Get the box with the better cost per marble a.k.a the lower c/m;
	Assume that you're using only those boxes and not the other.
	If they dont fit, try replacing one cheap box with one expensive.
	Keep replacing until u do it m_cheaper times and if none fit -> fail.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main(){

	long long n, m1, m2, c1, c2, cheaper_c, cheaper_m, expensive_c, expensive_m;
	bool m1_is_cheaper;

	cin >> n;
	while(n != 0){
		cin >> c1 >> m1 >> c2 >> m2;

		// Get the box with lower cost/marble;
		m1_is_cheaper = ((double)c1 / m1 <= (double)c2 / m2) ? true : false;

		//Store the correct values for cheaper and expensive variables.
		if(m1_is_cheaper){
			cheaper_m = m1;
			cheaper_c = c1;
			expensive_m = m2;
			expensive_c = c2;
		}
		else{
			cheaper_m = m2;
			cheaper_c = c2;
			expensive_m = m1;
			expensive_c = c1;
		}

		//Check if using any of (0) thru (cheaper_m) boxes will divide all marbles evenly;
		for(long long num_of_expensive_boxes_used = 0; num_of_expensive_boxes_used <= cheaper_m; ++num_of_expensive_boxes_used){
			int left_over_marbles_for_cheap_boxes_to_store = n - (num_of_expensive_boxes_used * expensive_m);
			
			//If we've made it this far without breaking, we've failed.
			if(num_of_expensive_boxes_used == cheaper_m || num_of_expensive_boxes_used * expensive_m > n){
				cout << "failed" << endl;
				break;
			}
			//If we can use only cheap boxes for left over marbles, great!
			if(left_over_marbles_for_cheap_boxes_to_store % cheaper_m == 0){
				//Condition to make sure we output in the right order.
				if(m1_is_cheaper){
					cout << (n - (num_of_expensive_boxes_used * expensive_m)) / cheaper_m << " " << num_of_expensive_boxes_used << endl;
				}
				else{
					cout << num_of_expensive_boxes_used << " " << (n - (num_of_expensive_boxes_used * expensive_m)) / cheaper_m << endl;

				}
				//Break out of for loop and get next input;
				break;
			}

		
		}


		cin >> n;

	}
	


	return 0;
}