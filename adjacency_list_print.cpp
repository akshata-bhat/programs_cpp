// Does not work ! segfaults

#include<iostream>
#include<vector>
using namespace std;


int main(){
	int V, E;
	int i, j, x, y;
	cin >> V;
	cin >> E;
	
	cout << "V: " << V << endl;
	cout << "E: " << E << endl;
	vector<int> adj[10];
	for(i=0; i<V; i++){
		cin >> x; 
		cin >> y;
		adj[x].push_back(y);
	}
	
	cout << "Printing the adjacency lists:" << endl;

	for(i=1; i<=V; i++){
		cout << "adjacency list for: " ;
		for(j=0; j<adj[i].size(); j++){
			cout << "->" << adj[i][j];
		}
		cout << endl;
	}
	return 0;
}
