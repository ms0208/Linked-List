//Reverse a Linked List in group of Given Size.
#include <iostream>
using namespace std;

// Linked List Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) {  // Constructor
        data = value;
        next = nullptr;
    }
};

// Function to reverse a linked list in groups of size k
Node* reverseInGroups(Node* head, int k) {
    if (!head) return nullptr;  // Base case: If the list is empty, return NULL.

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Step 1: Reverse first k nodes of the linked list
    while (current != nullptr && count < k) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move prev and current one step forward
        current = next;
        count++;
    }

    // Step 2: head is now the last node of the reversed group, so link it to the next group
    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
    }

    // Step 3: prev is the new head of the reversed group
    return prev;
}

// Utility function to insert a new node at the end of the list
void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the reverseInGroups function
int main() {
    Node* head = nullptr;
    // Creating the linked list 1->2->3->4->5->6->7->8
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);
    append(head, 8);

    cout << "Original List: ";
    printList(head);

    int k = 4;
    head = reverseInGroups(head, k);

    cout << "Reversed List in Groups of " << k << ": ";
    printList(head);

    return 0;
}
/*
Explanation (line by line):
struct Node: This defines a structure for a node in the linked list, with an integer data and a pointer next to the next node.

reverseInGroups(Node* head, int k): This function reverses the linked list in groups of size 
𝑘
k.

Base case (if (!head)): If the list is empty, return nullptr.

Initializations:

current = head: Points to the current node.
prev = nullptr: Tracks the previous node (used for reversing).
next = nullptr: Temporarily stores the next node.
Reversing the first 
𝑘
k nodes:

The while loop runs for 
𝑘
k iterations or until the end of the list.
Inside the loop:
next = current->next: Stores the next node.
current->next = prev: Reverses the current node’s pointer.
prev = current: Moves prev to the current node.
current = next: Moves current to the next node.
Recursion: After reversing the first 
𝑘
k nodes, the function calls itself to reverse the next group of 
𝑘
k nodes. The last node of the current group (head) is connected to the result of the next group's reversed nodes.

Return prev: This is now the new head of the reversed group.

Utility functions:

append: Adds nodes to the end of the linked list.
printList: Prints the linked list.
Example:
For the linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, and 
𝑘
=
3
k=3, the output would be:

mathematica
Copy code
Original List: 1 2 3 4 5 6 7 8
Reversed List in Groups of 3: 3 2 1 6 5 4 7 8
First group 1 -> 2 -> 3 is reversed to 3 -> 2 -> 1.
Second group 4 -> 5 -> 6 is reversed to 6 -> 5 -> 4.
The last group 7 -> 8 is smaller than 
𝑘
=
3
k=3, so it is not reversed.






*/