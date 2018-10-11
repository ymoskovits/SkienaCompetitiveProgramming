#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void fillRAM(int ram[]);
void clearRAM(int ram[]);
void clearRegisters(int registers[]);
int runAndCountCommands(int ram[], int registers[]);
void processInstruction(int ram[], int registers[], int instruction);



int main(){

	int ram[1000];
	int registers[10];
	string line;

	int cases, ans, val, ind;
	cin >> cases;

	for(int i = 1; i <= cases; ++i){
		clearRegisters(registers);
		clearRAM(ram);

		// get rid of empty lines before reading ram.
		while(true){
			getline(cin, line);
			if (line != ""){
				break;
			}
		}

		// ready to read and fill ram. Go until u get a blank line and end of a set.
		ind = 0;
		do{
			stringstream stream(line);
			stream >> val;
			ram[ind++] = val;

			// Corner Case: Detect the end of a file. Process the final set and return from main.
			if(!getline(cin, line)){
				ans = runAndCountCommands(ram, registers);
				cout << ans << endl;
				return 0;
			}
		}
		while(line != "");

		ans = runAndCountCommands(ram, registers);
		cout << ans << endl << endl;
	}
	return 0;	
}


void processInstruction(int ram[], int registers[], int instruction){
	int command = instruction/100;
	int tens = (instruction/10) % 10;
	int ones = instruction % 10;
	// cout << "About to process " << instruction << "..." << endl;
	switch(command){

		case 2:
			registers[tens] = ones;
			break;
		case 3:
			registers[tens] = (registers[tens] + ones) % 1000;
			break;
		case 4:
			registers[tens] = (registers[tens] * ones) % 1000;
			break;
		case 5:
			registers[tens] = registers[ones];
			break;
		case 6:
			registers[tens] = (registers[tens] + registers[ones]) % 1000;
			break;
		case 7:
			registers[tens] = (registers[tens] * registers[ones]) % 1000;
			break;
		case 8:
			registers[tens] = ram[registers[ones]];
			break;
		case 9:
			ram[registers[ones]] = registers[tens];
			break;
		default:
			cout << "END OF SWITCH" << endl;
	}
}


int runAndCountCommands(int ram[], int registers[]){
	int address = 0, instruction = 0, count = 0;
	while(true){
		count++;
		instruction = ram[address++];
		
		if(instruction/100 == 1){
			return count;
		}
		
		//Take care of special case where we might want to change the current address:
		if(instruction/100 == 0){
			
			//If register of last digit is 0 continue:
			if(registers[instruction%10] == 0){
				continue;
			}
			//Else change the address
			else{
				address = registers[(instruction/10) % 10];
			}
		}
		else{
			processInstruction(ram, registers, instruction);
		}
	}
}


void clearRegisters(int registers[]){
	for(int i = 0; i < 10; ++i){
		registers[i] = 0;
	}
	return;
}

void clearRAM(int ram[]){
	for(int i = 0; i < 1000; ++i){
		ram[i] = 0;
	}
	return;
}

// Make this work to have a function take care of input.
void fillRAM(int ram[]){
	string line;
	int ind = 0;
	int val;
	while(cin >> val){
		// getline(cin, line);
		
		// if (line == "\n"){
		// 	cout << endl << endl << line << endl << endl << endl;
		// 	cout << "END OF INPUT... " << ind << " vals were filled into ram.";
		// 	return;
		// }
		// val = stoi(line.c_str(), 0);
		// cout << val << endl;
		ram[ind++] = val;
	}
}	