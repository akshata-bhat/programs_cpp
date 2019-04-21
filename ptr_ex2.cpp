#include<iostream>
using namespace std;

void swap(int *a, int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{	
	int i=10, j=20;
	cout << "i = " << i << "\t j= " << j <<endl;
	swap(&i,&j);
        cout << "i = " << i << "\t j= " << j << endl;
	return 0;
}
