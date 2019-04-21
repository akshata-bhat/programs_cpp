#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next; 
};

class List{
private:
	Node* head = NULL;

public:
	void add_node_at_start(int value){
		Node* newNode = new Node();
		newNode->data = value;
		if(head == NULL){
			head = newNode;
			newNode->next = NULL;
		}
		else{
			newNode->next = head;
			head = newNode;
		}
	}
		
	void add_node_at_end(int value){
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if(head == NULL){
			head = newNode;
		}
		else {
			Node* temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}

	int delete_element_at_start(){
		if(head == NULL){
			cout << "Empty linked list; delete not done" << endl;
			exit(0);
		}
		else {	
			int value = head->data;
			Node* temp = head;
			head = temp->next;
			delete temp;
			return value;
		}
	}

	int delete_element_at_end(){
		if(head == NULL){
			cout << "Empty list" << endl;
			exit(0);
		}
		else{
			Node* temp = head;
			while(temp->next->next != NULL)
				temp = temp->next;
			int value = temp->next->data;
			temp->next = NULL;
			return value;	
		}	
	}
		
	void display_list(){
		Node* temp = head;
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse_linked_list(){
		int i=0;
		if(head != NULL || head->next != NULL){
			Node* prev = NULL;
			Node* current = head;
			Node* future = NULL;
			while(current != NULL){
				future = current->next;
				current->next = prev;
				cout << "current->next: " << prev <<endl;
				prev = current;
				current = future;
			}
			head = prev;
		}
	}

};

int main(){
	List l;
	l.add_node_at_end(10);
	l.add_node_at_start(20);	
	cout << "yo 1!" << endl;
	l.display_list();
	cout << "yo 2!" << endl;
	l.add_node_at_start(30);
	l.display_list();
	cout << "Node with value " << l.delete_element_at_end() << " deleted" <<endl;
	l.display_list();
	cout << "Node with value " << l.delete_element_at_start() << " deleted" << endl;
	l.display_list();
	l.add_node_at_end(34);
	l.add_node_at_end(35);
	l.add_node_at_end(36);
	l.display_list();

	l.reverse_linked_list();
	l.display_list();
	return 0;
}
