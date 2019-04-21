#include<iostream>
using namespace std;

struct Tnode {
        Tnode* left; 
        Tnode* right;
        int value;
};

Tnode* create_new_node(int data) {
        Tnode* temp = new Tnode();
        temp->value = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
}

Tnode* convert_arr_to_BST(int arr[], int start, int end) {
        if (start > end)
                return NULL;
        int mid = (start + end)/2;
        Tnode* root = create_new_node(arr[mid]);

        root->left = convert_arr_to_BST(arr, start, mid-1);

        root->right = convert_arr_to_BST(arr, mid+1, end);

        return root;
}


void preOrder_Traversal(Tnode* root) {
        if (root != NULL) {
                cout << root->value << " ";
                preOrder_Traversal(root->left);
                preOrder_Traversal(root->right);
        }
}

void inOrder(Tnode* root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->value << " ";
		inOrder(root->right);	
	}
}

void postOrder(Tnode* root){
	if(root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->value << " "; 
	}
}

int main(){
        int arr[] = {-10,-3,0,5,9};
        int n = sizeof(arr)/sizeof(arr[0]);
        Tnode* root = convert_arr_to_BST(arr, 0, n-1);
	cout << "PreOrder: " << endl;
        preOrder_Traversal(root);
	cout << "\nPostOrder: " << endl;
	postOrder(root);
	cout << "\nInOrder: " << endl;
	inOrder(root);
        return 0;
}
