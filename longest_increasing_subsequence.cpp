#include<iostream>
using namespace std;

int max_value(int arr[], int N) {
	int maxV = arr[0];
	for(int i=0; i<N; i++){
		if(arr[i] > maxV)
			maxV = arr[i];
	}
	return maxV;
}

int LIS(int arr[], int N){
	int lis[N];
	int i, j;
	for(i=0; i<N; i++)
		lis[i] = 1;

	for(i=1; i<N; i++){
		for(j=0; j<i; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j]+1;
//			cout << lis[i] << endl;
		}
	}
	
	return max_value(lis, N);
}

int main(){

	int arr[] = {10, 22, 9, 33, 21,  50, 41, 60};
	int len = sizeof(arr)/ sizeof(arr[0]);
	int lis_len = LIS(arr, len);
	cout << "Length of longest increasing sequence: " << lis_len << endl;
	return 0;
}
