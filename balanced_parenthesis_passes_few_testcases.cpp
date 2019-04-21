#include <bits/stdc++.h>
#include <stack>
using namespace std;

string isBalanced(string s) {
    // Complete this function
    int len = s.length();
    char temp;
    if(len%2 != 0)
        return "NO";
    else{
        stack <char> stac;
        for (int i=0; i<len/2; i++){
            stac.push(s[i]);
        }
        
        for(int i=len/2; i<len; i++){
            temp = stac.top();
            stac.pop();
            if(temp == '('){
                if(s[i] == ')')
                    continue;
                else 
                    return "NO";
            }
            else if(temp == '['){
                if(s[i] == ']')
                    continue;
                else 
                    return "NO";
            }
            else if(temp == '{'){
                if(s[i] == '}')
                    continue;
                else 
                    return "NO";
            }
        }
        return "YES";           
    }
}
    

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}

