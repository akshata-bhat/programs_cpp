#include <iostream>
using namespace std;

int main(){
	int arr[7] = {9,8,6,4,1,8,1};
	int index, value, len = 7;
	// Here indexing starts from i=1 because you are trying to set the limited for the sorted and the unsorted arrays
	for(int i=1; i<7; i++){
		value = arr[i];
		index = i;
		while(index>0 && arr[index-1] > value){
			arr[index] = arr[index-1];
			index = index - 1;
		}
		arr[index] = value;
	} 
	
	// printing the array
	for(int i=0; i<7; i++)
		cout << arr[i] << endl;
	return 0;
}
