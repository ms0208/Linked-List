//Can we reverse a linked list in less than O(n) ?
// Reversing a linked list in less than O(n) time complexity is not possible due to the nature 
//of linked lists and the operations involved. Here's why:

// ### Explanation:
// 1. **Access Time:** Linked lists do not allow random access like arrays. To reverse the list,
// you need to traverse through each node at least once, which inherently takes O(n) time,
// where n is the number of nodes in the list.

// 2. **Reversing Process:** To reverse a linked list, you need to change the `next` pointers of
// each node. This requires visiting each node to make the necessary changes, which involves 
//O(n) operations.

// ### Complexity Breakdown:
// - **O(n):** You must visit each node once to reverse it. The time complexity is proportional
// to the number of nodes.
// - **O(1):** The space complexity can be O(1) if you reverse the list in place, meaning you 
//don't use any additional data structures to store the nodes.

// ### Example of Reversing a Linked List in O(n):
// Here’s a simple implementation in C++ that reverses a linked list in O(n) time complexity:

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    return prev; // New head of the reversed list
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original List: ";
    printList(head);

    head = reverseLinkedList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}
// ### Summary:
// - Reversing a linked list requires O(n) time complexity.
// - You cannot achieve this in less than O(n) due to the need to visit each node.
// - The process can be done in O(1) space if reversed in place, meaning no extra space
// is used for storage.

// If you have any specific use cases or optimizations in mind, feel free to share!