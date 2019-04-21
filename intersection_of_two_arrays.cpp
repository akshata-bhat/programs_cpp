#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	vector<int> a2 = {1, 2, 3, 5, 6, 8};
	vector<int> a1 = {0, 7, 8, 6, 1};
	
	vector<int> result;
	int i;
	
	map<int, bool> temp;
	for(i=0; i<a1.size(); i++){
		if(temp.find(a1[i]) == temp.end())
			temp[a1[i]] = 1;
	} 
		
	for(i=0; i<a2.size(); i++){
		if(temp.find(a2[i]) != temp.end()){
			result.push_back(a2[i]);
			cout << a2[i] << endl;
		}
	}
	return 0;	
}

