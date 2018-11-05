#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head = NULL;
    void insert_node(int data){
        ListNode* newNode = new ListNode(data);
        if(head == NULL)
            head = newNode;
        else{
            //ListNode* temp = new ListNode();
            ListNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }     
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //ListNode* itr1 = new ListNode();
        ListNode* itr1 = l1;
        //ListNode* itr2 = new ListNode();
        ListNode* itr2 = l2;
        
        while(itr1 != NULL || itr2 != NULL){
            
            // When List 1 is empty
            if(itr1 == NULL && itr2 != NULL){
                insert_node(itr2->val);
                itr2 = itr2->next;
            }
            
            // When List 2 is empty
            else if(itr2 == NULL && itr1 != NULL){
                insert_node(itr1->val);
                itr1 = itr1->next;
            }
            
            // When List 1 value <= List 2 value
            else if(itr1->val < itr2->val){
                insert_node(itr1->val);
                itr1 = itr1->next;
            }
            
            // When List 2 value < List 1 value
            else if(itr2->val < itr1->val){
                insert_node(itr2->val);
                itr2 = itr2->next;
            }
            else if(itr2->val == itr1->val){
                insert_node(itr1->val);
                insert_node(itr2->val);
                itr1 = itr1->next;
                itr2 = itr2->next;
            }   
        }
        return head;
    }
};
