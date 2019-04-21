#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
	int i, index = 0; // index is tracking the indices of the words being added to the vector
	vector<string> words;
	string s1 = "Alice wins Bob";
	string s2 = "";
	for(i=0; i<s1.length(); i++){
		words.push_back("");
		while((s1[i] != ' ') && (i < s1.length())){
			words[index] += s1[i]; //Appending one character at a time for that word
			i++;
		}
		index++; // There is no need to add an extra i++ here, since the for loop at the top taskes care of it.
	}

	for(i=0; i<words.size(); i++)
		cout << words[i] << endl;

	for(i=words.size()-1; i>0; i--){
		s2 += words[i];
		s2 += " ";
	}
	s2 += words[0];  // This first word is added out of the loop to prevent addition of an extra space
	
	cout << "Final string: " << s2 << endl;
	return 0;
}
