#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node* newnode(int value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = value;
	newNode->left = NULL; 
	newNode->right = NULL;
	return newNode;
}

void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}	
}

struct node* insert_node(struct node* temp, int key){
	if(temp == NULL) return newnode(key);
	
	if(key < temp->key)
		temp->left =  insert_node(temp->left, key);
	else if(key > temp->key)
		temp->right =  insert_node(temp->right, key);

	return temp;
}


int main(){
	struct node* root = NULL;
	root = insert_node(root, 50);
	insert_node(root, 30);
	insert_node(root, 20);
	insert_node(root, 70);
	insert_node(root, 60);
	insert_node(root, 40);
	insert_node(root, 80);
	inorder(root);
	return 0;
}
