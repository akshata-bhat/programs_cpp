#include<iostream>
#include<string>
using namespace std;

string compress_string(string str){
	string result = "";
	char temp;
	int i, count;
	int len = str.length();
	
	for(i=0; i<len; i++){
		temp = str[i];
		count = 0;
		while((str[i] == temp)  && (i<len)){
			count++; i++;		
		}
		result += temp;
		result += to_string(count);
	}
	if(result.length() < len)
		return result;
	else
		return str;
}
int main(){
	string str = "abca";
	cout << "Original string: " << str << endl;
	cout << "Compressed Result: "<< compress_string(str) << endl;
	return 0;	
}
