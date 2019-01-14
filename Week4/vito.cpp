#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main(){

	int num_of_sets, num_of_neighbors, cur, dist, med;
	vector<int> list_of_neighbors;
	string line;

	cin >> num_of_sets;
	for(int set = 0; set < num_of_sets; ++set){
		list_of_neighbors.clear();
		cin >> num_of_neighbors;
		dist = 0;
		for(int neighbor = 0; neighbor < num_of_neighbors; ++neighbor){
			cin >> cur;
			list_of_neighbors.push_back(cur);	
		}
		// cout << "AVG: " << sum/num_of_neighbors << endl;
		sort(list_of_neighbors.begin(), list_of_neighbors.end());
		med = list_of_neighbors[list_of_neighbors.size()/2];
		for(int neighbor = 0; neighbor < num_of_neighbors; ++neighbor){
			dist += abs(med - list_of_neighbors[neighbor]);
		}

		cout << dist << endl;

	}

	return 0;
}