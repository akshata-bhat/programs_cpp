#include<iostream>
#include<map>
#include<string>
#include<bitset>
using namespace std;

int is_unique_map(string s){
	int len = s.length();
	// No. of unique ascii characters is 128
	if(len > 128)
		return -1;
	map<char, bool> list;
	for(int i=0; i<len; i++){
		if(list.count(s[i]))
			return -1;
		list[s[i]]=1;
	}
	return 1;
}

int is_unique_bitset(string s){
	bitset<256> bits(0);

	for(int i=0; i<s.length(); i++){
		int val = s[i];
		if(bits.test(val) > 0)
			return -1;
		bits.set(val);
	}
	return 1;
}

int main(){
	int result;
	string str = "brown";
	result = is_unique_map(str);
	(result == -1) ? cout << "Not unique\n" : cout << "Unique word\n"; 
	result = is_unique_bitset(str);
        (result == -1) ? cout << "Not unique\n" : cout << "Unique word\n"; 
	return 0;
}
