#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

//Node* head = NULL;

class list{
	private:
		Node* head;
	public:
		list(){
			head = NULL;
		}

		~list(){
			cout << "Object destroyed" << endl; 
		}

		void insert_node_at_end(int value){
			Node* new_node = new Node();
			new_node -> data = value;
			new_node -> next = NULL;
			
			if(head == NULL)
				head = new_node;
			else{
				Node* temp = new Node();
				temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = new_node;
			}
		}

		void insert_node_at_start(int value){
			Node* new_node = new Node();
			new_node->data = value;	
			if(head == NULL){
				head = new_node;
				new_node->next = NULL;
			} else {
				new_node->next = head;
				head = new_node;
			}	
		}
		
		void delete_node_at_start(){
			if(head == NULL)
				cout << "Empty list - can't delete a node" << endl;
			else{
				Node* temp = new Node();
				temp = head;
				head = temp->next;
				delete temp;
			}	
		}
		
		void delete_node_at_end(){	
			if(head == NULL)
				cout << "Empty list" << endl;
			else{
				Node* current_node = new Node();		
				current_node = head;
				Node* prev_node = current_node;		
				while(current_node->next != NULL){
					prev_node = current_node;
					current_node = current_node->next;
				}
				prev_node->next = NULL;
				delete current_node;
			}	
		}
		
		void delete_node_at_ptr(Node* ptr){
			Node* temp = new Node();
			temp = ptr;
			ptr->data = ptr->next->data;
			ptr->next = ptr->next->next;
			delete ptr;					
		}	

		Node* display_middle_element(){
			Node* fast = head;
			Node* slow = head;
			// The fast pointer is traversing two nodes at a time and the slow pointer is traversing one node at a time
			// fast!=NULL : To stop when the fast pointer reaches the end for a even lenght array
			// fast->next!=NULL : To stop when the fast pointer reaches the end for an odd lenght array 	
			while(fast != NULL && fast->next != NULL){
				fast = fast->next->next;		
				slow = slow->next;
			}
			cout << "Middle element: " << slow->data << endl;
			return slow->next;
		}		
			
		void reverse_linked_list(){
			Node* previous = NULL;
			Node* current = head;
			Node* future = NULL;
			while(current != NULL){
				future = current->next;
				current->next = previous;
				previous = current;
				current = future;
			}	
			head = previous;
		}
						
		void display()
		{
			Node* temp = new Node;
			temp = head;
			while(temp!=NULL){
				cout << temp->data <<"\t";
				temp=temp->next;
			} 	
			cout<<endl;
		}
};

int main()
{
	list L;
	L.delete_node_at_start();
	L.insert_node_at_end(10);
	L.insert_node_at_end(20);
	L.insert_node_at_end(30);
	L.display();
	L.delete_node_at_end();
	L.insert_node_at_end(40);
	L.insert_node_at_start(50);
	L.insert_node_at_start(60);
	L.display();
	L.delete_node_at_start();
	L.display();
	L.delete_node_at_end();
	L.display();
	
	Node* temp;
	temp = L.display_middle_element();
	
	//delete_node_at_ptr	
	L.insert_node_at_end(80);
	L.insert_node_at_end(90);
	L.insert_node_at_end(100);
	L.reverse_linked_list();
	L.display();
	cout << "Deleting node at ptr" << endl;
	L.delete_node_at_ptr(temp);
	L.display();
}	
