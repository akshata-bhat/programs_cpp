// Check if a phone number is found in a directory

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;


int main() {
    int number, n;
    string name;
    cin >> n;
    cin.ignore();
    
    map <string, long> phoneBook;
    for(int i=0; i<n; i++){
        cin >> name;
        cin >> number;
        phoneBook[name]=number;
    }
    
    string search_ptr;
    while(cin >> search_ptr){
        if(phoneBook.count(search_ptr) > 0) // Returns a 1 if the name is found in the map
            cout << search_ptr << "=" << phoneBook[search_ptr]<< endl;
        else 
            cout << "Not found" << endl;
    }
    return 0;
}
