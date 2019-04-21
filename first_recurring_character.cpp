#include<iostream>
#include<map>
#include<string>
using namespace std;

char first_recurring(string s){
	map<char, int> tbl;

	for(int i=0; i<s.length(); i++){
		if(tbl.find(s[i]) != tbl.end())
			return s[i];
		else
			tbl[s[i]] = 1;
	}
	return NULL;
}
	
int main(){
	string s1 = "hello";
	char result = first_recurring(s1);
	(result == NULL) ? cout << " No Recurring element" : cout << "recurring character- "<< result << endl;

	return 0;
}
