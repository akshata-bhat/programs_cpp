#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node* nextRight;
}; 

Node* new_node(int value){
	Node* temp = new Node();
	temp->left = NULL;
	temp->right = NULL;
	temp->nextRight = NULL;
	temp->data = value;

	return temp;
}

void connect(Node* root){
	if(root == NULL)
		return;
	
	queue<Node* > q;
	q.push(root);
	q.push(NULL); // To mark the end of the first level after the root
	while(q.empty() != true){
		Node* p = q.front();
		q.pop();

		if(p != NULL){
			p->nextRight = q.front();

			if(p->left != NULL)
				q.push(p->left);
			if(p->right != NULL)
				q.push(p->right);
		}
		else if(q.empty() == false){ // this case will be entered for the first level,"root connected to null"
			q.push(NULL); // you are pushing back NULL since you removed it at the beginning of the while loop	
		}
	}
}

int main(){
	Node *root = new_node(1);
        root->left = new_node(2);
        root->right = new_node(3);
        root->left->left = new_node(4);
        root->left->right = new_node(5);
        root->right->right = new_node(6);
        root->left->right->right = new_node(7);
        root->right->right->left = new_node(8);

	connect(root);

    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in \n"
                   "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight ? root->right->right->nextRight->data : -1);
	return 0;
}
