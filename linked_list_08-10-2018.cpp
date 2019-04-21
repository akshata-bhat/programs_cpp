#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class linked_list{
private:
	Node* head;

public:
	linked_list(){
		head = NULL;
	}
	
	void insert_node_beginning(int value){
		Node* newNode = new Node();
		newNode->data = value;
		if(head == NULL){
			head = newNode;
			newNode->next = NULL;
		} else {
			newNode->next = head;
			head = newNode;
		}
		cout << "inserted " << value << " at the start" << endl;
	}

	void insert_node_end(int value){
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		if(head == NULL){
			head = newNode;
		}
		else{
			Node* temp = new Node();
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cout << "inserted " << value << " at the end" << endl;		
	}
	
	int delete_node_at_start(){
		if(head == NULL){
			cout << "Empty list" << endl;
			exit(0);
		}
		else{
			Node* temp = head;
			int value = temp->data;  
			head = head->next;
			delete temp;
			return value;
		}
	}
	
	int delete_node_at_end(){
		if(head == NULL){
			cout << "Empty list" << endl;
			exit(0);
		}
		else{
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			int val = temp->data;
			temp = NULL;
			cout << "deleting" << endl;
			return val;
		}
	}
	
	void display_list(){
		Node* temp = new Node();
		temp = head;
		while(temp != NULL){
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main(){
	int val;
	linked_list L;
	L.insert_node_beginning(90);
	L.insert_node_end(20);
	L.insert_node_beginning(30);
	L.insert_node_end(40);
	L.insert_node_end(50);
	L.display_list();
	val = L.delete_node_at_end();
	cout << "Deleted node's val: " << val;
	return 0;
}

