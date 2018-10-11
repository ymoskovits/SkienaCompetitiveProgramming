#include <iostream>

using namespace std;

int main(){
	int n, m;
	char cur;
	int field = 0;
	cin >> n >> m;
	//Go until n and m are 0.
	while (true){
		field++;
		
		if(n == 0 && m == 0){
			return 0;
		}

		char** grid = new char*[n];
		char** res = new char*[n];

		for(int i = 0; i < n; ++ i){
			grid[i] = new char[m];
			res[i] = new char[m];
		}

		
		//Fill in grid with input and initialize res:
		for(int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				//Fill in grid:
				cin >> cur;
				grid[i][j] = cur;
				//Initialize res:
				if(cur == '*'){
					res[i][j] = '*';
				}
				else{
					res[i][j] = '0';
				}
			}
		}

		//For each element in grid, if its a mine, add one to each neighbor:
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(grid[i][j] == '*'){
					//Iterate through all neighbors of grid[i][j];
					for(int k = i-1; k <= i+1; ++k){
						for(int l = j-1; l <= j+1; ++l){
							//Check bounds of k and l:
							if(k < 0 || k >= n || l < 0 || l >= m){
								continue;
							}
							//If this neighbor isnt a mine, increment its count:
							if(grid[k][l] != '*'){
								res[k][l] = res[k][l] + 1;
							}
						}
					}
				}
			}
		}

		cout << "Field #" << field << ":" << endl;

		for (int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << res[i][j];
			}
			cout << endl;
		}


		cin >> n >> m;
		if(n == 0 && n == 0) return 0;

		cout << endl;


	}
	
	return 0;
}