#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

	int numOfStudents = 0;
	string cash;

	while (true){
		cin >> numOfStudents;

		if (numOfStudents == 0){
			return 0;
		}

		float total = 0, avgCost = 0, moneySwapped = 0;
		float* cashSpent = new float[numOfStudents];

		for (int i = 0; i < numOfStudents; i++){
			cin >> cash;
			cashSpent[i] = strtof((cash).c_str(),0);
			// cashSpent[i] = std::floor(cashSpent[i] * 1000 + 0.5) / 1000;
		}

		
		for (int i = 0; i < numOfStudents; i++){
			total += cashSpent[i];
		}

		avgCost = total / numOfStudents;
		// avgCost *= 100;
		// int intAvgCost = (int) avgCost;
		// avgCost = (double)intAvgCost / 100.0;
		avgCost = floor(avgCost * 100 ) / 100;		

		for (int i = 0; i < numOfStudents; i++){
			if (cashSpent[i] < avgCost){
				moneySwapped += (avgCost - cashSpent[i]);
			}
		}
		// while(fmod(moneySwapped, numOfStudents) != 0.0){
		// 	// moneySwapped += 0.01;
		// }

		// cout << setprecision(2) << fixed;
		// cout << "$" << floor(moneySwapped * 100 + .5) / 100 << endl;

		printf("$%.2f\n", moneySwapped);

		delete[] cashSpent;
	}

}