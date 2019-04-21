#include<iostream>
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
		
		void insert_node_at_start(int value){
			Node* newNode = new Node();
			newNode->data = value;
			if(head == NULL)
				head = newNode;
				newNode->next = NULL;
			else{
				Node* temp = head;
				head = newNode;
				newNode->next = temp;
			}
		}

		int delete_node_at_end(){
			if(head == NULL){
				cout << "Empty list" << endl;
				exit(0);	
			}
			else{
				Node* temp = head;
				while(temp->next != NULL)
					temp = temp->next;
				int value = temp->data;
				temp = NULL;

			}
		}	
};

int main(){
	
	return 0;
}
