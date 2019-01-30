#include <iostream>
#include <vector>
#include <unordered_map> 
#include <unordered_set> 
#include <list>
#include <utility>
#include <queue> 
#include <iterator>

using namespace std;

bool are_doublets(string a, string b){
	bool found_swap_char = false;
	if(a.length() != b.length()){
		return false;
	}
	for(int i = 0; i < a.length(); ++i){
		if(a[i] != b[i]){
			if(found_swap_char){
				return false;
			}
			else{
				found_swap_char = true;
			}
		}
	}
	return true;
}


class Graph{
	int verticies;
	unordered_map<string, list<string> > adjLists;
	unordered_set<string> visited; 

public:
	void add_vert(string new_string){
		if(adjLists.find(new_string) != adjLists.end()){
			return;
		}
		list<string> new_list;
		for(unordered_map<string, list<string> >::iterator it = adjLists.begin(); it != adjLists.end(); ++it){
			if(are_doublets(new_string, (*it).first)){
				// cout << "Adding " << new_string << " to " << (*it).first << "s list of neighbors " << endl;
				(*it).second.push_back(new_string); //instead of//p.second.push_back(new_string);
				// cout << (*it).second.back() << endl;
				new_list.push_back((*it).first);
			}
		}
		adjLists[new_string] = new_list;
		adjLists.insert(make_pair(new_string, new_list));
	}

	void print(){
		for(pair<string, list<string> > p : adjLists){
			// cout << "String " << p.first << " is connected to:" << endl;
			for(string s : p.second){
				// cout << "\t" << s << endl;
			}
		}
	}

	string bfs(string from, string to){
		if(from.length() != to.length()){
			return "No solution.\n";
		}
		if(adjLists.find(from) == adjLists.end() || adjLists.find(to) == adjLists.end() ){
			return "No solution.\n";
		}

		if(adjLists.size() == 0){
			return "No solution.\n";
		}
		if(adjLists.size() == 1){
			if(from == to && adjLists.find(from) != adjLists.end() ){
				return from + "\n";
			}
			else{
				return "No solution.\n";
			}
		}

		if(from == to){
			if(adjLists.find(from) != adjLists.end()){
				return from + "\n";
			}
			else{
				return "No solution.\n";
			}
		}

		visited.clear();
		string origin = from, path;
		// vector<pair<string, pair<string, int>>> processed;
		queue<pair<string, string> > q;
		q.push(make_pair(from, from));
		visited.insert(from);
		while(!q.empty()){
			if(q.front().first == to){
				return q.front().second + "\n";
			}
			from = q.front().first;
			path = q.front().second;
			q.pop();
			list<string> from_list = adjLists[from];
			for(string s : from_list){
				if(visited.find(s) == visited.end()){
					q.push(make_pair(s, path + "\n" + s));
					visited.insert(s);
					// cout << "adding : path to __" + s + "__ is " + path + "\n" + s;
				}
				else{
					// cout << "Else";
				}
			}
		}
		return "No solution.\n";

	}

};

int main(){

	string word, from, to;
	Graph doublets_graph;
	vector<Graph> graphs(20);
	getline(cin, word);
	while(word != ""){
		graphs[word.length()].add_vert(word);
		getline(cin, word);
	}


	cin >> from;
	while(true){
		if(cin >> to){

		}
		else{
			break;
		}
		cout << graphs[from.length()].bfs(from, to);
		if(cin >> from){
			cout << "\n";
		}
	}

	return 0;
}









