#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	vector<int> x{1,3,5,6,9,9,9};
	x.push_back(5);
	x.push_back(9);
	x.push_back(9);
	x.push_back(5);
	x.push_back(3);
	x.push_back(0);
	x.push_back(1);
	x.push_back(9);
	int map_val;
	//vec.erase(vec.begin() + index);
	//it = find (myvector.begin(), myvector.end(), 30);
	
	map<int,int> values;
	for(int i=0; i<x.size(); i++){
		if(values.find(x[i]) == values.end())
			values[x[i]] = 1;
		else
			values[x[i]] += 1;	
	}

	

	for (auto& itr : values){
    	std::cout << itr.first << " " << itr.second << endl;
	}

	

//	vector<int> unique_val;
//	for(int i=0; i<x.size(); i++)
//		if(vec.end() != find(vec.begin(), vec.end(), ser))
			
	for(int i=0; i<x.size(); i++)
		cout << x[i] << endl;
	return 0;
}
