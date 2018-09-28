#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
//	node(int x) : val(x), left(NULL), right(NULL) {}
};

node* create_newnode(int value){
	node* temp = new node();
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* insert_node(struct node* temp, int value){
	if(temp == NULL) return create_newnode(value);
	
	if(value < temp->data)
		temp->left = insert_node(temp->left, value);
	else if(value > temp->data)
		temp->right = insert_node(temp->right, value);

	return temp; 
}

void preOrder(node* root){
	if(root != NULL){
		cout << root->data << endl;
		preOrder(root->left);
		preOrder(root->right);
	}	
}

void inOrder(node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}	
}

void postOrder(node *root) {
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << endl;
    }
}

int main(){
	node* root = NULL;
	root = insert_node(root, 50);
	insert_node(root, 30);
	insert_node(root, 20);
	insert_node(root, 40);
	insert_node(root, 70);
	insert_node(root, 60);
	insert_node(root, 80);
	cout << "PostOrder" << endl; 
	postOrder(root);
	cout << "Preorder" << endl;
	preOrder(root);
	cout << "Inorder" << endl;	
	inOrder(root);
	return 0;
}
