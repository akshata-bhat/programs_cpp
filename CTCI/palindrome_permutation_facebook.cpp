#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool check_permutation (string s){
	bool flag=false;
	unordered_map<char, int> tbl;
	
	for(int i=0; i<s.size(); i++){
		if(s[i]!=' ')
			tbl[s[i]]++;
	}

	for(auto i: tbl){
		if(i.second%2 == 0)
			continue;
		else if(i.second%2==1 && flag!=true)
			flag = true;
		else 
			return false;
	}
	return true;
}

int main(){
	string s = "taco cat";
	bool result = check_permutation(s);
	cout << result << endl;
	return 0;
}
