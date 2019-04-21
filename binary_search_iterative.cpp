#include<iostream>
using namespace std;

int binary_search(int arr[], int key, int len){
	
	int mid, low=0;
	int high = len - 1;

	while(low < high){
		mid = float(high+low)/2.0;
		if(arr[mid] == key){
			cout << "element found" << endl;
			return mid;
		}
		else if(key < arr[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
}

int main(){
        int arr[6] = {34, 78, 9, 2, 83, 22};
        int key = 83;
	int len = sizeof(arr)/sizeof(arr[0]);

	int position = binary_search(arr, key, len);

	cout << "The element was found at positon " << position+1 << endl;
	return 0;
}

