#include <iostream>
using namespace std;

int main() {
	int temp=0;
	int min, position, i, j, len;
	cout << "Enter the total number of integers to be sorted and the integers to be sorted one below another" << endl;
	//cin >> len;
	len = 9;
	int a[len] = { 10, 9, 6, 5, 4, 3, 4, 2 ,1 };
	//for (i = 0; i < len; ++i)
	//{
	//	cin >> a[i];	}
	for(i = 0; i<len; i++){
		min = a[i];
		for(j=i; j<len; j++)
		{
			if(a[j] < min){
				min = a[j];
				position = j;		
			}
		}
		temp = a[i];
		a[i] = min;
		a[position] = temp;
	}
	
	for(int i=0; i<len; i++)
		cout << a[i] << endl;
	return 0;
}
