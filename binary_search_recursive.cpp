#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int low, int high, int key){
	if(low < high){	
		int mid = (high)/2;
		if(arr[mid] == key)
			return mid;
		else if(key < arr[mid])
			return binary_search(arr, low, mid-1, key);
		else if(key > arr[mid]) 
			return binary_search(arr, mid+1, high, key);
	}
	return -1;
}

int main(){
	vector<int> v1 = {8, 5, 8, 9, 2, 1};
	int position = binary_search(v1, 0, v1.size()-1, 8);
	if(position == -1)
		cout << "Element not found" << endl;
	else 
		cout << "Element found at position " << position+1 << endl;	
}
