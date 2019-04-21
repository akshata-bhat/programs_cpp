#include<iostream>
using namespace std;



	struct node{
		int data;
		node* left;
		node* right;
	};

	node* create_node(node* temp, int value){
		temp = new node();
		temp->data = value;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	
		
	node* insert_node(node* root, int value){
		if(root==NULL)
			return create_node(root, value);
		if(value < root->data)
			root->left = insert_node(root->left, value);
		else if(value > root->data)
			root->right = insert_node(root->right, value);
		return root;
	}
	
	void inOrder(node* root) {
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}

	void postOrder(node* root){
		postOrder(root->left);
		postOrder(root->right);
                cout << root->data << endl;
	}	

	void preOrder(node* root){
		cout << root->data << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
	
	int main(){
        node* root = NULL;
        cout << "Root: " << root << endl;
        root = insert_node(root, 80);
        cout << "Root: " << root << endl;

        insert_node(root, 30);
        cout << "Root: " << root << endl;

        insert_node(root, 20);
        cout << "Root: " << root << endl;

        insert_node(root, 60);
        insert_node(root, 90);

        cout << "Root: " << root << endl;
	inOrder(root);
}


