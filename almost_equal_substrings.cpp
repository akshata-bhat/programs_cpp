/*Split the input string into specified number of almost same sized sub-strings

- Make sure all the substrings are divided in sequence and can be later built up- the substrings should be printed in decreasing length order

*/

//To compile:  g++ -std=c++11 almost_equal_substrings.cpp 

//SOLUTION
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

void print_substrings(vector<int> lengths, string str){
	int i, index = 0;
	for(i=0; i<str.length();){
		cout << lengths[index] << endl;
		cout << str.substr(i, lengths[index]) << endl;
		i=i+lengths[index];
		index++;
	}	
}	

int main(){
	string str = "abcdefghi";
	int n = 3;
	int sub_len, len = str.length();

	vector<int> sub_lengths;
	
	while(n>0){
		cout << "Lenght of str: " << len;
		cout << "Value of n: " << n;
		if(len%n != 0){
			sub_len = ceil(float(len)/n);
		}
		else{
			sub_len = len/n;
		}
                cout << "Substring length: " << sub_len << endl;
                sub_lengths.push_back(sub_len);
                len = len - sub_len;
                n--;
	
	}
	cout << "lengths: " << endl;
	for(int i=0; i<sub_lengths.size(); i++)
		cout << sub_lengths[i] << endl;
	print_substrings(sub_lengths, str);
	return 0;
}
	
	
