#include<iostream>
using namespace std;

bool isSubstring(string s1, string s2){
	int i, j, k;
	for(i=0; i<s2.length(); i++)
	{
		j=0;
		k=i;
		while(s1[j] == s2[i] && j<s1.length()){
			i++; j++;
			cout << "i: " << i << " j: " << j << endl;
		}
		if(j==s1.length())
			return true;
		else
			i=k;	
	}
	return false;
}

int main(){
	string s1 = "yellow";
	string s2 = "owyell";

	string s3 = s2 + s2;
	cout << s1 << " " << s2 << " " << s3<< endl;
	bool result = isSubstring(s1, s3);
	if(result == true)
		cout << "s2 can be rotated to get s1" << endl;
	else
		cout << "s2 and s2 not same" << endl;
	return 0;
}
