#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    string toHex(int num) {
        string s ="";
        vector<char> hex_values;
        hex_values = {'1', '2', '3', '4','5','6','7','8','9','a','b','c', 'd', 'e', 'f'};
        vector<char> result;
        int remainder;
        while(num >= 0){
            result.push_back(num%16); 
            num = num/16;
        }
        reverse(result.begin(),result.end());
        for(int i=0; i<result.size();i++)
        {
            s += result[i];
        }
        return s;
    }
};

int main(){
	Solution ans1;
	cout << ans1.toHex(26);
	return 0;
}
