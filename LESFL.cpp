//Write a Program to Move the last element to Front in a Linked List.
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;      // Stores the data of the node
    Node* next;    // Pointer to the next node
};

// Function to move the last node to the front
void moveLastToFront(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;  // If the list is empty or has only one node, no changes needed
    }

    Node* secondLast = NULL;  // Pointer to track second-last node
    Node* last = *head;       // Pointer to track the last node

    // Traverse the list to find the second-last and last nodes
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // The last node is now at 'last', and second last is 'secondLast'
    
    secondLast->next = NULL;  // Disconnect second last node from the last node
    last->next = *head;       // Make the last node point to the current head
    *head = last;             // Move the last node to the front by updating the head
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";  // Print each node's data
        head = head->next;          // Move to the next node
    }
    cout << endl;
}

// Function to push a new node at the beginning
void push(Node** head, int newData) {
    Node* newNode = new Node();  // Allocate memory for the new node
    newNode->data = newData;     // Set the new node's data
    newNode->next = *head;       // Link the new node to the current head
    *head = newNode;             // Update the head to the new node
}
// Function to push a new node at the end
// it use to push at end remembered we add later to learn push at end.
void pushAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Allocate memory for the new node
    newNode->data = newData;     // Set the new node's data
    newNode->next = NULL;        // New node will be the last, so set next to NULL

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // Move to the next node
    }

    // Link the last node to the new node
    temp->next = newNode;
}

int main() {
    Node* head = NULL;  // Initialize an empty linked list

    // Create the linked list 1 -> 2 -> 3 -> 4 -> 5
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Original List: ";
    printList(head);  // Print the original list

    moveLastToFront(&head);  // Move the last element to the front

    cout << "Modified List: ";
    printList(head);  // Print the modified list
    return 0;
}
