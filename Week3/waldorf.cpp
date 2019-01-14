#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

char** fill_grid(int m, int n);
bool valid_match(char **grid, string word, int m, int n, int row, int col);

int main(){
	int num_of_sets, m, n, words;
	cin >> num_of_sets;
	string line;
	bool found;

	for(int set = 0; set < num_of_sets; ++set){
		getline(cin, line);
		cin >> m >> n;
		char **grid = fill_grid(m, n);

		cin >> words;
		for(int count = 0; count < words; ++count){
			cin >> line;
			//Convert the string to lowercase.
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			//Flag to indicate when we've found the word.
			found = false;
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(grid[i][j] == line[0] && valid_match(grid, line, m, n, i, j)){
						cout << i+1 << " " << j+1 << endl;
						found = true;
						break;
					}
				}
				if(found){
					break;
				}
			}
		}

		if(set != num_of_sets - 1){
			cout << endl;
		}

		for(int i = 0; i < m; ++i){
			delete[] grid[i];
		}
		delete[] grid;

	}
	return 0;
}

char** fill_grid(int m, int n){
	char in;
	char **grid = new char*[m];
	for (int i = 0; i < m; ++i){
		grid[i] = new char[n];
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> in;
			grid[i][j] = tolower(in);
		}
	}
	return grid;
}

/*
	Class Incrementor is simply a container for 2 vars:
	x_delta and y_delta
	Each of which can take on values of either -1, 0, +1.

	Let me know how you think enums can improve this.
	I have a feeling there's a good way but not sure.
*/
class Incrementor{
	public:
		int x_delta;
		int y_delta;

	void set_values(int direction){
		if(direction == 4 || direction < 0 || direction > 8){
			throw "INVALID DIRECTION";
		}
		if(direction < 3){
			x_delta = -1;
			y_delta = (direction % 3) - 1;
		}
		else if(direction < 6){
			x_delta = 0;
			y_delta = (direction % 3) - 1;
		}
		else{
			x_delta = 1;
			y_delta = (direction % 3) - 1;
		}
	}
};

bool valid_match(char **grid, string word, int m, int n, int row, int col){
	Incrementor step;
	int temp_row, temp_col;
	bool from_break = false;
	/*
		Step can understand each number between 0-8 as a direction to move in.
		We can therefore simply go through a loop and pass the loop iterator to the set_values function in each iteration.
	*/
	for(int direction = 0; direction <= 8; ++direction){
		temp_row = row;
		temp_col = col;
		//Case where x_delta and y_delta are both 0.
		if(direction == 4){
			continue;
		}
		step.set_values(direction);
		from_break = false;
		//Try out this direction
		for(int letter = 1; letter < word.size(); ++letter){
			//Go to the letter'th spot.
			temp_col += step.x_delta;
			temp_row += step.y_delta;
			//Check if it's in bounds.
			if(temp_row >= m || temp_row < 0 || temp_col >= n || temp_col < 0){
				from_break = true;
				break;
			}
			//Get out if the word doesn't match.
			if(grid[temp_row][temp_col] != word[letter]){
				from_break = true;
				break;
			}
		}
		//How did we get out of the loop?
		if(from_break){
			continue;
		}
		else{
			return true;
		}
	}
	return false;
}




