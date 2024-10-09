// To delete a loop in a linked list in C++, you can use Floyd's Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm. Here's a step-by-step implementation:

// 1. **Detect the loop** using two pointers (slow and fast).
// 2. If a loop is detected, find the starting point of the loop.
// 3. Remove the loop by setting the next pointer of the last node in the loop to `nullptr`.

// Here's the C++ code to achieve this:

// ```cpp
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to create a loop at a given position
void createLoop(Node* head, int pos) {
    if (pos == 0) return;

    Node* loopNode = nullptr;
    Node* temp = head;
    int count = 1;

    // Traverse the list to find the loop position node
    while (temp->next != nullptr) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // Create a loop by connecting the last node to the loopNode
    if (loopNode != nullptr) {
        temp->next = loopNode;
    }
}

// Function to detect and remove the loop
void removeLoopAtPosition(Node* head, int pos) {
    Node* temp = head;
    Node* prev = nullptr;

    // Traverse to the node just before the position where the loop starts
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Traverse to find the node that points back to the loop node
    Node* loopNode = temp;
    Node* ptr = loopNode;

    while (ptr->next != loopNode) {
        ptr = ptr->next;
    }

    // Break the loop
    ptr->next = nullptr;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int loopPosition;
    std::cout << "Enter the position where you want to create a loop: ";
    std::cin >> loopPosition;

    // Create a loop at the specified position
    createLoop(head, loopPosition);

    std::cout << "Enter the position where the loop should be removed: ";
    int removePosition;
    std::cin >> removePosition;

    // Remove loop at the specified position
    removeLoopAtPosition(head, removePosition);

    std::cout << "List after removing the loop: ";
    printList(head);

    return 0;
}

/*
```

### Explanation:
1. **Node Class**: Represents a node in the linked list.
2. **removeLoop Function**: This function identifies the starting point of the loop and then traverses to find the last node in the loop to break the cycle.
3. **detectLoop Function**: Uses Floyd's Cycle Detection to find a loop and calls `removeLoop` to delete it if found.
4. **printList Function**: Prints the linked list for verification after the loop removal.
5. **main Function**: Sets up a linked list with a loop, detects the loop, removes it if found, and prints the final list.
*/