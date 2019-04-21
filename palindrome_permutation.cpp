#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string s1 = "tac oacT";
    int len = s1.length();
    map<char, int> table;
    for(int i=0; i<len; i++){
        if(s1[i] == ' ')
            continue;
        table[s1[i]]++;
    }
    
    int count=0;
    int val;
    map<char, int> :: iterator it;
    for(it=table.begin(); it!=table.end(); ++it){
        val = it->second % 2;
        count += val;
    }
    
    if(count == 0 || count == 1)
        cout << "Yes permutation of palindrome" << endl;
    else
        cout << "No" << endl;
    return 0;
}
