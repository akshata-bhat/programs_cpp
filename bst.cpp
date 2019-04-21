#include<iostream>
using namespace std;

struct treeNode{
	int val;
	treeNode* right;
	treeNode* left;
	treeNode(int x): val(x), left(NULL), right(NULL){}
};

treeNode* create_new_node(int x){
        treeNode* temp = new treeNode(x);
        return temp;
}

treeNode* insert_node(treeNode* root, int x){
	if(root == NULL)
		return create_new_node(x);
	else if(x <= root->val)
		root->left = insert_node(root->left, x);
	else if(x > root->val)
		root->right = insert_node(root->right, x);
	return root;
}

void inOrder(treeNode* root){
	if(root != NULL){
		inOrder(root->left);
		cout << root->val << endl;
		inOrder(root->right);
	}
}

void preOrder(treeNode* root){
	if(root != NULL){
		cout << root->val << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(treeNode* root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << endl;
	}
}	
	

int main(){
	treeNode* root = NULL;
	root = insert_node(root, 10);
	insert_node(root, 23);
	insert_node(root, 2);
	insert_node(root, 44);
	insert_node(root, 86);
	insert_node(root, 12);

	cout << "Inorder Traversal" << endl;
	inOrder(root);
	
	cout << "Preorder"<< endl;
	preOrder(root);
		
	cout << "PostOrder" << endl;
	postOrder(root);
	
	int a = 10;
	unsigned int b;
	int c = -20;

	cout << a << endl;
	b = a;
	cout << char('a' + b - 10)<< endl;
	b = c;
	cout << 'a' + b - 10 << endl;
	return 0;
}
