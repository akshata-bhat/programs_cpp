#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool check_one_edit_away(string s1, string s2){
	short flag = 0; 
	unordered_map<char, int> tbl;
	
	for(int i=0; i<s1.length(); i++){
		tbl[s1[i]]++;
	}
	
        for(int i=0; i<s2.length(); i++){
                tbl[s2[i]]--;
        }
	
	for(auto k: tbl){
		if(k.second == 0)
			continue;
		else if((k.second == 1 || k.second == -1) && flag < 2)
			flag++;
		else
			return false;
	}
	return true;
}

int main(){
	bool result = check_one_edit_away("pale", "bale");
	cout << "Final result: "<< (bool)result << endl;
	return 0;
}


