#include<iostream>
#include<string>
using namespace std;

int main(){
	string a1 = "elhel";
	string a2 = "hello";

	string temp = a1+a1;
	
	int result = temp.find(a2);

	if(result != string::npos)
		cout << "true" << endl;
	else
		cout << "false" ;
	
}
