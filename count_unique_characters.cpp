#include<iostream>
#include<string.h>
using namespace std;

int main()
{	
	int i,j, index=0, count=1;
	string s="waterproof test";
	for(i=0; i< s.length();i++)
		cout << s[i] << endl;
	for(i=0; i<s.length(); i++){
		count=1;
		if(s[i] == '*')
			continue;
		for(j=i+1; j<s.length(); j++){
			if(s[i] == s[j] && s[i]!='*' && s[j]!='*' ){
				count++;
				s[j]='*';
			}
		}
		cout << "Character "<< s[i] << " appears " << count << " times" << endl;
	}	
	return 0;
}
