//Multiply 2 no. represented by LL
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
void insertlist(Node** head , int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = nullptr;
    if(*head==nullptr)
    {
        *head = newnode;
    }
    else {
    Node* temp = *head;
    while(temp->next!= nullptr)
    {
        temp = temp->next;
    }
      temp->next =  newnode;
    }
}
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node();  // Allocate memory for a new node
    newNode->data = data;        // Assign data to the new node
    newNode->next = *head;       // Link the new node to the current head
    *head = newNode;             // Update head to the new node
}
void printlist(Node *head)
{
    if(head==nullptr)
    {
        cout<<"List is empty";
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout<< 2*(temp->data)<<" ";
        temp = temp->next;
    }
    cout<< endl;
}
int main()
{
    Node* head = nullptr;
    insertlist(&head , 1);
    insertlist(&head , 2);
     insertlist(&head , 3);
    printlist(head);
}