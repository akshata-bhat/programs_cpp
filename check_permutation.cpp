#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_permutation(string s1, string s2){
	vector<int> list1(128, 0);
	vector<int> list2(128, 0);
	
	int len1 = s1.length();
	int len2 = s2.length();
	int val;
	if(len1 != len2)
		return 0;

	for(int i=0; i<len1; i++){
		val = s1[i];
		cout << "val 1: " << val << endl;
		list1[val]++;
		cout << "list1: " << list1[val] << endl;
	}
	
	for(int i=0; i<len2; i++){
		val = s2[i];
		cout << "val 2: " << val << endl;
		list2[val]++;
		cout << "list2: " << list2[val] << endl;
	}	
	
	for(int i=0; i<128; i++){
		cout << list1[i] << "\t" << list2[i] << endl;
		if(list1[i] != list2[i])
			return 0;
	}
	return 1;
}

int main(){
	string s1 = "olaaa";
	string s2 = "olaoo";
	bool result = is_permutation(s1, s2);
	(result == 0) ? cout << "Not a permutation\n" : cout <<  "Yes, a permutation\n";
	return 0;	
}
