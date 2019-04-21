#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	//vector<int> arr();
	//{9, 2, 5, 1, 4};
	bool swapped = false;
	int arr[5] = {1,1,1,1,1};
	int len = 5;
	for(int i=0; i<len; i++){
		for(int j=0; j<len-i; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false){
			cout << "Array sorted" << endl;
			break;
		}
	}
	for(int i=0; i<len;i++)
		cout << arr[i] << endl;
	return 0;
}
