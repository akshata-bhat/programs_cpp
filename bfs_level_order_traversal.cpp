#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* new_node(int value){
	TreeNode* newNode = new TreeNode();
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

void print_level_order_traversal(TreeNode* root){
	TreeNode* temp;
	if(root == NULL)
		return;

	queue<TreeNode* > q;
	q.push(root);
		
	while(q.empty() == false){
		temp = q.front();
		cout << temp->data << " ";
		q.pop();

		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}

int main(){
	TreeNode *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->right = new_node(6);
	root->left->right->right = new_node(7);
	root->right->right->left = new_node(8);
	print_level_order_traversal(root);
	return 0;
}
