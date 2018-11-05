/*
In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in minimum number of questions.

*/


#include <iostream>
using namespace std;
#define N 4
bool matrix[N][N] = {{0,0,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,1,0}};

bool knows(int a,int b){
	return matrix[a][b];
}

int check_celebrity(int n)
{
	int a = 0;
	int b = n-1;
	
	//keep iterating until the pointers are not the same
	while(a<b)
	{
		if(knows(a,b))
			a++;
		else
			b--;
	}

	//check if the person is a celebrity
	for(int i=0; i<n; i++)
	{
		if((a!=i) && (knows(a,i)==0 || knows(i,a)!=0))
			return -1;
	}
	return a;	
}

int main()
{
	int n=4;
	int id = check_celebrity(n);
	id == -1 ? cout << "No celebrity" : cout << "Celebrity id" << id;
	return 0;
}

