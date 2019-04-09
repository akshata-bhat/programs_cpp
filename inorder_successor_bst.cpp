/* Lintcode:
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

Example
Example 1:
Input: tree = {1,#,2}, node value = 1
Output: 2
Explanation:
  1
   \
    2
    
Example 2:
Input: tree = {2,1,3}, node value = 1
Output: 2
Explanation: 
    2
   / \
  1   3

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
     
    // Finding the left most node in the tree as per the logic that in an inorder traversal, order is left->root->right, 
    // and since we are coming from the root node, the next node will be the left-most node in the tree 
    TreeNode* find_min(TreeNode* root){
        if(root == nullptr)
            return nullptr;
        while(root->left!=nullptr){
            root = root->left;
        }
        return root;
    }   
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr)
            return nullptr;
        
        // Initializing the successor is important here, since for the case where the target node is the right 
        // most node in the tree and does not have a successor, the successor will automatically be assigned to null.   
        TreeNode* successor = nullptr; 
        while(root != nullptr){
            // if the root node's value is < target node's value, then the target node will occur on the right 
            // branch(BST property: left val < root val < right val). hence move to right branch 
            if(root->val < p->val)
                root = root->right;
                
            // if the target node's value is less than the current root value, then we have to move to the left branch. 
            // also if the target value is lower, it is possible that the target node might not have a right branch/node whose
            // value will be greater than the root's value, thereby making the root node the successor(min largest number) 
            else if(root->val > p->val){
                successor = root;
                root = root->left;
            }
            // if we find the root's value to match target node value, then find the right branch's left most element 
            //(i.e the smallest element in that branch)
            else if(root->val == p->val){
                if(root->right != nullptr){
                    successor = find_min(root->right);
                }
                break;
            }
        }
        return successor;
    }
};
