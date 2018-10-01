/*

Input Format

The first line contains an integer T,  (the number of test cases). 
Each line  of the T subsequent lines contain a String, .

Sample Input
2
Hacker
Rank

Sample Output
Hce akr
Rn ak

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    string input, odd, even;
    int len;
    cin.ignore();
    for(int i=1; i<=T; i++){
        input="";
        odd="";
        even="";
        getline(cin, input);
        for(int j=0; j< input.length(); j++){
            if(j%2 == 0)
                even=even+input[j];
            else 
                odd = odd+input[j];
        }
        even=even+"\0";
        odd=odd+"\0"; 
        cout << even << " " << odd << endl;
    }
    return 0;
}

