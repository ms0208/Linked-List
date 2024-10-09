#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {} // Constructor to initialize node
};

// Function to segregate even and odd nodes in the linked list
Node* segregateEvenOdd(Node* head) {
    // Pointers to store the head of even and odd lists
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* current = head; // Start with the head of the original list

    // Traverse through the original linked list
    while (current != NULL) {
        // Check if the current node's data is even or odd
        if (current->data % 2 == 0) {
            // If it's even, add it to the even list
            if (evenHead == NULL) {
                evenHead = current; // Set evenHead if it's the first even node
                evenTail = current; // Initialize evenTail
            } else {
                evenTail->next = current; // Link to the next even node
                evenTail = evenTail->next; // Move evenTail to the new last even node
            }
        } else {
            // If it's odd, add it to the odd list
            if (oddHead == NULL) {
                oddHead = current; // Set oddHead if it's the first odd node
                oddTail = current; // Initialize oddTail
            } else {
                oddTail->next = current; // Link to the next odd node
                oddTail = oddTail->next; // Move oddTail to the new last odd node
            }
        }
        current = current->next; // Move to the next node in the original list
    }

    // If there are no even nodes, return the odd list
    if (evenHead == NULL) {
        return oddHead;
    }

    // If there are even nodes, link the last even node to the head of the odd list
    evenTail->next = oddHead;

    // Set the next of the last odd node to NULL to terminate the list
    if (oddTail != NULL) {
        oddTail->next = NULL;
    }

    // Return the head of the even list
    return evenHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "Segregated list: ";
    printList(head);

    return 0;
}
