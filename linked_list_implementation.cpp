#include <iostream> 
using namespace std; 
  
// Source for this program :  
//https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr  
  
int i; 
struct node 
{ 
    int data; 
    node* next;  
}; 
  
class list{ 
    private: 
        node* head; 
        node* tail; 
    public: 
    list() // Contructor which initializes the head and tail of the pointer to null 
    { 
        head=NULL; 
        tail=NULL;  
    } 
     
    ~list() // Destructor 
    { 
        cout << "Object destroyed" << endl; 
    } 
void add_node_at_end(int value) // To add a node at the end of the list 
{ 
    node* temp = new node; 
    temp->data=value; 
    temp->next=NULL; 
    if(head==NULL) // To check if the list is empty  
    { 
        head = temp; 
        tail = temp; 
        temp = NULL; 
    } 
    else 
    { 
        tail->next=temp; 
        tail=temp; 
    } 
} 
  
node* add_node_at_begin(int value, node* head) 
{ 
    node* temp = new node; 
    temp->data = value; 
    temp->next = head; 
    head=temp; 
    cout << "New address of head : " << head; 
    return head; 
} 
  
void add_node_at_particular_address(int value, node* prev) 
{ 
    node* temp = new node; 
    temp->data = value; 
    temp->next=prev->next; 
    prev->next=temp;  
} 
  
void add_node_at_position(int value, int pos) 
{ 
    node* temp=new node; 
    node* current=new node; 
    node* previous=new node; 
    current=head; 
    for(i=1;i<pos;i++) 
    { 
        previous=current; 
        current=current->next; 
    } 
    previous->next=temp; 
    temp->next=current; 
    temp->data=value; 
} 
  
node* delete_node_at_end(node* head) 
{ 
    node* temp=new node; 
    node* before_end=new node; 
    temp=head; 
    while(temp->next != NULL) 
    { 
        before_end=temp->next; 
        temp=before_end; 
    } 
    tail=before_end; 
    before_end->next=NULL; 
    return tail; 
} 
  
node* delete_node_at_start(node* head) 
{ 
    node* temp=new node; 
    temp=head->next; 
    head=temp; 
    return head; 
} 
  
void delete_node_at_position(int pos, node* head) 
{ 
    node* current=new node; 
    node* previous=new node; 
    current=head; 
    for(i=1;i<pos;i++) 
    { 
        previous=current; 
        current=current->next; 
    } 
    previous->next=current->next; 
} 
void display()  //To display the contents of the linked list; 
{ 
    node* temp = new node; 
    temp = head; 
    while(temp!=NULL) 
    { 
        cout << temp->data << "\t"; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
}; 
  
int main() 
{ 
    list obj; 
     
    obj.add_node_at_end(10); 
    obj.add_node_at_end(20); 
    obj.add_node_at_end(30); 
    obj.add_node_at_end(40); 
     
    cout << "Displaying all nodes" << endl; 
    obj.display(); 
     
    return 0; 
} 