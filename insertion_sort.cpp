#include <iostream>
using namespace std;

int main()
{
	int key, i, j, len=8;
	int a[len] = {9, 8, 6, 5, 4, 3, 2, 1};

	for(i=1; i<len; i++)
	{
		key = a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}

	for(i=0; i<len; i++)
		cout << a[i] << endl;

	return 0;
}