#include <iostream>
using namespace std;

// Time complexity = O(N2) n square
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int i, j, temp = 0, len = 6;
	bool swapped;
	int a[len] = {5, 4, 3, 2, 1, 0};

	for(i=0; i< len-1; i++){
		swapped = false;
		for(j=0; j<len-i-1; j++){
			if(a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
				//temp = a[j+1];
				//a[j+1] = a[j];
				//a[j] = temp;
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}
	for(i=0; i< len; i++)
		cout << a[i] << endl;
	return 0;
}