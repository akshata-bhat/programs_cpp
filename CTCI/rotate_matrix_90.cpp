#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int>> &vect){
	int height = vect.size();
        int width = vect[0].size();

	cout << height << width << endl;
        for(int i=0; i<width; i++){
                for(int j=i; j<height; j++){
                        swap(vect[i][j], vect[j][i]);
                }
        }
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void swap_columns(vector<vector<int>> &vect){
        int height = vect.size();
        int width = vect[0].size();
	int start = 0, end = width-1;
        for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                        start = j;
                        end = (width-1) -j;
			if(start <= end){
                        	swap(vect[i][start], vect[i][end]);
                	}
		}
        }
}

void print_matrix( vector<vector<int>> &vect){
        int height = vect.size();
        int width = vect[0].size();
        for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                        cout << vect[i][j] << " ";
                }
                cout << endl;
        }

}
int main(){
	// This code only works for a square matrix
	 vector<vector<int> > vect{ { 1, 2, 3 , 10}, 
                                    { 4, 5, 6 , 20},
				    { 2, 4, 5, 11},
                                    { 7, 8, 9 , 30} };
	print_matrix(vect);
	transpose(vect);
	print_matrix(vect);
	swap_columns(vect);
	print_matrix(vect);
	return 0;
}

