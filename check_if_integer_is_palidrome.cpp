#include <iostream>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    struct Node{
        int data;
        Node* next;
    };
    
    Node* stackHead = NULL;
    
    void pushValue(int value){
        Node* newNode = new Node;
        newNode->data = value;
        if(stackHead == NULL){
            stackHead = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next = stackHead;
            stackHead = newNode;
        }
    }
   
    int popValue(){
        if(stackHead == NULL)
            exit(0);
        Node* temp = new Node;
        temp = stackHead;
        int value = temp->data;
        stackHead = temp->next;
        delete temp;
        return value;
    }
    
    void display(){
        Node* temp = new Node;
	temp = stackHead;
        while(temp != NULL){
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    
/*
    bool isPalindrome(int x) {
            
    }
*/
};

int main(){

	Solution ans1;
	int val;
	ans1.pushValue(10);
	ans1.pushValue(20);
	ans1.pushValue(30);
	ans1.pushValue(40);
	ans1.display();

	val = ans1.popValue();
	cout << "Popped value: " << val << endl;
	
	val = ans1.popValue();
	cout << "Popped val: " << val << endl;

	cout << "Values on the stack" ;
	ans1.display();
	return 0;
}
