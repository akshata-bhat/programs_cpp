#include<iostream>
using namespace std;

int MAX=4;
int main()
{	
	char *names[]={"Ali", "Elephant", "Agony", "Pant"};
	cout << "Pointer address \t Names" << endl;
	for(int i=0; i< MAX; ++i)
		cout << names[i] << "\t" << *names[i] << endl;
	return 0;

}
