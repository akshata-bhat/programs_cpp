#include <iostream>
using namespace std;

int interpolation_search(int* arr, int len, int target);

int main(){
	int arr[5] = {9,8,13,131,10};
	int len = 5, target = 10;
	int position = interpolation_search(arr, len, target);
	if(position == -1)
		cout << "Element not found" << endl;
	else 
		cout << "Element found at "<< position << endl;
	return 0;
}

int interpolation_search(int arr[], int len, int target){
	int start = 0;
	int end = len - 1;
	int pos;
	for(int i=0; i<len; i++)
		cout << arr[i] << endl;
	while(start<=end && target>=arr[start] && target<=arr[end]){
		pos = start + double((end - start)/(arr[end] - arr[start])) * (target - arr[start]);		
		if(target == arr[pos])
			return pos;
		else if(target > arr[pos])
			start = pos + 1;
		else if(target < arr[pos])
			end = pos - 1;
	}
	return -1;
}
