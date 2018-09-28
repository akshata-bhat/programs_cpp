#include<stdlib.h>
#include<stdio.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node* newNode(int item){
	struct node* temp = (struct node* )malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)


