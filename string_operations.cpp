#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char s1[] = "hello";
	string s2 = "madam";
	
	char* val = strchr(s1, 'a');
	cout << val - s1 +1;
	return 0;
}
