/*
The problem is asking for the minimum spanning tree of a connected graph of all points listed.
I use the principle proven in prim's algorithm to solve it.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

//Easy way to track the location of a single point. x and y coordinates
class Point{
public:
	double x;
	double y;
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}

	void operator=(Point other){
		this->x = other.x;
		this->y = other.y;
	}

	double operator-(Point other){
		return sqrt( pow(this->x - other.x, 2) + pow(this->y - other.y, 2) );
	}

	~Point(){}	
};



//This function will find the closest point to the already included points.
//It returns a pair with the indices of the included point and the non-included point.
pair<int, int> closest_point_index_to_included(vector<Point>& included, vector<Point>& points){
	double min_dist = included[0] - points[0]; 
	pair<int, int> indices(0,0);
	for(int i = 0; i < included.size(); ++i){
		for (int j = 0; j < points.size(); ++j){	
			if(included[i] - points[j] < min_dist){
				min_dist = included[i] - points[j];
				indices.first = i;
				indices.second = j;
			}
		}
	}
	return indices;
}



int main(){
	int num_of_sets;
	double x, y;
	//The points vector will hold the points that aren't yet added to the tree.
	//The included vector will hold the points that have been included already in the tree.
	vector<Point> points, included; 

	//INPUT
	cin >> num_of_sets;
	for(int set = 0; set < num_of_sets; ++set){
		double total = 0;
		int num_of_points;
		included.clear();
		points.clear();
		cin >> num_of_points;
		//Load points into vector.
		for(int point = 0; point < num_of_points; ++point){
			cin >> x >> y;
			points.push_back(Point(x,y));
		}

		//Get started with including the first point of the min spanning tree randomly.
		included.push_back(points.back());
		points.pop_back();

		for(int point = 0; point < num_of_points - 1; ++point){
			pair<int,int> edge_vertices_indexes = closest_point_index_to_included(included, points); // function returns first the verticie in the connected component and then the vertice not int connected component.
			Point vertice_to_use = included[edge_vertices_indexes.first];	//Set the value for the point that you want to use which was included in the tree so far.
			Point closest = points[edge_vertices_indexes.second];	//Set the value for the non-included point that is closest to the point we chose.
			included.push_back(points[edge_vertices_indexes.second]);	//Add that point to included.
			points.erase(points.begin() + edge_vertices_indexes.second);	//Erase it from points.

			total += abs(vertice_to_use - closest);	//Add that distance to the total.
		}

		if(set == num_of_sets - 1){
			printf("%.2f\n", total);
		}
		else{
			printf("%.2f\n\n", total);
		}

		
	}


	return 0;
}











