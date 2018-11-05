#include <iostream>
#include <stdlib.h>
#include <math.h>
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
    

    bool isPalindrome(int x) {
	if(x < 0)
		return false;
	else if(x%10 ==0)
		return false;
	else{
		int n=x, remainder, reversed_x=0, val;
		int count = 0;
	
		while(n>0){
			cout << "n = " << n << "remainder = " << remainder << endl;
			remainder = n%10;
			this->pushValue(remainder);
			cout << "hello";
			n=n/10;
			count++;
		}
		this->display();
		int ten_power = 0;	
		while(count > 0){
			val = this->popValue();
			cout << "val = " << val;
			reversed_x += pow(10,ten_power)*val;
			cout << "building the number: " << reversed_x << endl;
			--count;
			++ten_power;
		}

		if(reversed_x == x)
			return true;
		else 	
			return false;
	}     
    }
};

int main (int argc, char *argv[]){

	Solution ans1;
	/*
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
	*/

	int a = -2037;
	int b = 8118;
	int c = 3403;

	bool result;
	int number = atoi(argv[1]); 
	cout << number;
	result = ans1.isPalindrome(number);
	if(result)
		cout << number << " is a Palindrome" << endl;
	else 
		cout << number << " is not a Palindrome" << endl;	
	return 0;
}
