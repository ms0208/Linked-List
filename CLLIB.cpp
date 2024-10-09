
#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Constructor to initialize the node with data and next pointer
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
void insertatbegin(node *&head, int val) {
    node* newnode = new node(val);
    // Point the new node's next to the current head
    newnode->next = head;
    // Update the head to the new node
    head = newnode;
}

// Print the linked list
void printlinkedlist(node *head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node* head = nullptr;
    insertatbegin(head , 1);
    insertatbegin(head , 2);
    printlinkedlist(head);
}