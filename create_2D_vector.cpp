// Define the 2D vector with different sizes of column input by user
/*
Input : Number of rows : 5 
        Number of columns in rows : 
        2 3 4 5 1
Output : 1 2
         1 2 3
         1 2 3 4
         1 2 3 4 5 
         1

*/


#include<iostream>
#include<vector>
using namespace std;

//int main(int argc, char* argv){
int main(){
	int k;
	int  rows = 3;
	vector<int> col_len{4, 3, 1};
	vector< vector<int> > vec(rows);
	
	for(int i=0; i<col_len.size(); i++){
		k = 1;
		vec[i] = vector<int> (col_len[i]);
		for(int j=0; j<col_len[i]; j++){
			vec[i][j] = k;
			k++;	
		}
	}

	cout << "Printing the vector" << endl;
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); j++){
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
