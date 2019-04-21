#include<iostream>
using namespace std;

int main()
{
	int *ptr;
	int **ptr_to_ptr;
	int element=3000;
	
	ptr=&element;
	ptr_to_ptr=&ptr;
	
	cout << "Value of ptr to ptr = " << *ptr_to_ptr << endl;
	cout << "Value of ptr = " << *ptr << endl; 
	return 0;
}
