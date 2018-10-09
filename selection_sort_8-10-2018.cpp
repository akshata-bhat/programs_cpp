#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int arr[7] = {3,9,2,8,45,2,5};
	int i, j, min_index, len = 7;
	for(i=0; i<len; i++){
		min_index = i;
		for(j=i+1; j<len; j++){
			if(arr[j] < arr[min_index])
				min_index = j; 
		}
		swap(&arr[i], &arr[min_index]);
	}

	for(i=0; i<len; i++)
		cout << arr[i] << endl;
	return 0;
}

