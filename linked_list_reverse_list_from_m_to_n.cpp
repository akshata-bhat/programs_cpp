#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next; 
};

class reverse_list{
	Node* head;

	public:
	reverse_list():head(NULL) {}
	~reverse_list(){
		cout << "Object destroyed" << endl;}
	
	void insert_node_at_end(int value){
		Node* new_node = new Node();
		new_node->data = value;
		new_node->next = NULL;

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

	void display_list(){
		Node* temp ;
		temp = head;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse_list_within_range(int m, int n){
		int count = 1, length = 0;
		Node* current = head;
		Node* previous = head;
		Node* start, end;
		//Counting the number of elements in the list
		while(current!=NULL){
			++length;
			if(count == m){
				start = previous;
			}
			if(count == n){
				end = previous;
			}
			previous = current;
			current = current->next;
		}
		
		reverse_linked_list(start_ptr, end_ptr)
		// Check if m < n < lenght - if the program fails
		
		while(temp!=NULL){
			if
		}
	}	

	void reverse_linked_list(Node* start_ptr, Node* end_ptr){
		Node* previous = start_ptr;
		Node* current = head;
		Node* future = end_ptr;
		
		while(current != NULL){
			future = current->next;
			current->next = previous;
			previous = current;
			current = future;
		}
		head = previous;
		cout << "Last output of current"<< current << endl; 
	}
};

int main(){
	reverse_list List;
	List.insert_node_at_end(50);
	List.insert_node_at_end(40);
	List.insert_node_at_end(30);
	List.insert_node_at_end(20);
	List.insert_node_at_end(10);
	
	List.display_list();
	List.reverse_linked_list();	
	List.display_list();
	return 0;
}
