#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1 = "Mr John Smith    ";
	int trueL = 13;
	int givenL = s1.length();
	cout << "Orig string: " << s1 << endl;
	int k = givenL-1;	
	for(int i=trueL-1; i>=0; i--){
		if(s1[i] == ' '){
			s1[k--] = '0';
			s1[k--] = '2';
			s1[k--] = '%'; 
		}
		else
			s1[k--] = s1[i];
	}
	cout << "New string: " << s1 << endl;
	return 0;
}
