#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node * newNode(int k)
{
    Node *temp = new Node;
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool find_path(Node* root,vector<int> path, int k);

int findLCA(Node* root, int k1, int k2){
	vector<int> path1, path2;
	int i;
	if(find_path(root, path1, k1) == false || find_path(root, path2, k2) == false)
		return -1;

	for(i=0; i< (path1.size() && path2.size()); i++){
		if(path1[i] != path2[i])
			break;
	}
	return path1[i];
}


bool find_path(Node* root,vector<int> path, int k){
	if(root == NULL)
		return false;

	if(root->data == k)
		return true;
	
	path.push_back(root->data);
	
	if((root->left && find_path(root->left, path, k)) || (root->right && find_path(root->right, path, k)))
		return true;

	path.pop_back();
	return false;
}

int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    //root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "LCA(3, 6) = " << findLCA(root, 3, 6) << endl;
    cout << "LCA(3, 5) = " << findLCA(root, 3, 5) << endl;
    cout << "LCA(2, 6) = " << findLCA(root, 2, 6) << endl;
    return 0;
}
