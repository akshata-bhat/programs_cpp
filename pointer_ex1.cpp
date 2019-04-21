#include<iostream>
using namespace std;

void print_array(int *list, int len)
{
	for(int i=0; i<len; i++)
		cout << list[i] << endl;
}

int main()
{	
	int length = 3;
	int list[3]={1,2,4};
	print_array(list, length);
	return 0;
}
