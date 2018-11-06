/*

In this challenge, you must first implement a queue using two stacks. Then process "q" queries, where each query is one of the following  types:

1 x: Enqueue element "x" into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

First line : number of queries
First value of each line after that: type
If first value = 1, second value = x

Sample input:
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2

Sample output:
14
14

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution{
    stack<int> s1;
    
    stack<int> s2;
    public:
        void enqueue(int x){
            //Assuming stack 1 is of infinite length
                s1.push(x);
        }
        
        // Same function is used for printing the value on the top of the queue and to pop a value from queue
        void dequeue(bool just_print){
            if(s1.empty() && s2.empty()){
                cout << "Empty" << endl;
                exit(0);
            }
            else{
                if(s2.empty()){
                    while(!s1.empty()){
                        //cout << "s1 top: " << s1.top() << endl;
                        s2.push(s1.top());
                        //cout << "s2 top: " << s2.top() << endl;
                        s1.pop();
                    }
                }
                int value = s2.top();
                //If just_print = true, then print value on the top of the queue
                if(just_print)
                    cout << value << endl;
                else 
                    s2.pop();
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q; int type; int x;
    cin >> q; // query count
    Solution ans;
    
    while(q>0){
        cin >> type;
        switch(type){
            case 1:
                cin >> x;
                ans.enqueue(x);
                break;
            case 2:
                ans.dequeue(0);
                break;
            case 3:
                ans.dequeue(1);
                break;
            default:
                break;
        }
        q--;
    }
    return 0;
}

