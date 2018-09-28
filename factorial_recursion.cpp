#include<iostream>
using namespace std;

class Fact
{
	public:
	int factorial(int n)
	{
		if(n>1)
			return factorial(n-1) * n;
		else
			return 1;
		
	}	
};

int main()
{
	int result, n=4;
	Fact obj;
	result = obj.factorial(n);
	cout << "The factorial of " << n << " = " << result << endl;
	return 0;
}
