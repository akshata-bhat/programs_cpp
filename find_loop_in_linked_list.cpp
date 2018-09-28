#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class List{
	private: 
	Node* head;
	
	public:	
	List(){
		head = NULL;
	}	
	
	~List(){
		cout << "Object destroyed" << endl;
	}
	
	bool check_loops_in_list(){
		if(head == NULL)
			cout << "Empty list" << endl;
		else{
			Node* slow = head;	
			Node* fast = head;
			
			while(fast!=NULL && fast->next != NULL){	
				fast=fast->next->next;
				slow=slow->next;
				if(slow == fast)
					return True; 	
			}	
		}
	}
};
