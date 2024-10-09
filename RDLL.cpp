// Reverse a doubly linked list.
#include <iostream>
using namespace std;

// Node of a doubly linked list
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node
};

// Function to reverse the doubly linked list
void reverseDoublyLinkedList(Node*& head) {
    Node* temp = nullptr;   // Temporary node for swapping
    Node* current = head;   // Starting with the head node

    // Traverse the list and swap next and prev pointers for each node
    while (current != nullptr) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the list (which is current->prev after swap)
        current = current->prev;
    }

    // After the loop, temp will be pointing to the old head
    if (temp != nullptr) {
        head = temp->prev;  // Set the new head of the list
    }
}

// Utility function to print the doubly linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert a node at the end of the list
void append(Node*& head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (head == nullptr) {
        new_node->prev = nullptr;
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

int main() {
    Node* head = nullptr;

    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    cout << "Original list: ";
    printList(head);

    // Reversing the doubly linked list
    reverseDoublyLinkedList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
/*
1<->2<->3<->4
prev = null;
current = 1 
next = 2;
temp = null
current->prev = current->next
current->prev = 2
current->next = null
2-1-null

2-3-4
4-3-2 swap
3-4
4-3 swap
4-3-2-1-null
*/