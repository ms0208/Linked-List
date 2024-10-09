//Write a program to Detect loop in a linked list.
/*
To detect a loop in a linked list, one of the most common algorithms used is Floyd’s Cycle 
Detection Algorithm, also known as the "Tortoise and Hare" algorithm. In this algorithm, 
two pointers (slow and fast) traverse the list at different speeds. If there is a cycle (loop),
 they will meet at some point; otherwise, the fast pointer will reach the end of the list.
*/
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;  // Pointer to the next node
};

// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    Node* slow = head;  // Slow pointer moves one step at a time
    Node* fast = head;  // Fast pointer moves two steps at a time

    // Traverse the list with two pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;  // Move slow pointer one step
        fast = fast->next->next;  // Move fast pointer two steps

        // If the slow and fast pointers meet, there is a loop
        if (slow == fast) {
            return true;
        }
    }

    // If fast pointer reaches the end (nullptr), there is no loop
    return false;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Function to create a loop at the given position
void createLoop(Node* head, int position) {
    if (position == 0) return;  // No loop if position is 0

    Node* temp = head;
    Node* loopNode = nullptr;
    int counter = 1;

    // Traverse to the position where the loop is to be created
    while (temp->next != nullptr) {
        if (counter == position) {
            loopNode = temp;  // Remember the node where loop should start
        }
        temp = temp->next;
        counter++;
    }

    // Point the next of the last node to the loopNode
    temp->next = loopNode;
}

int main() {
    // Example to create a linked list and test loop detection
    Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);

    int position;
    cout << "Enter the position where the loop should start (enter 0 for no loop): ";
    cin >> position;

    // Create loop based on user input
    createLoop(head, position);

    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No Loop detected." << endl;
    }

    return 0;
}

/*
Explanation:
Node Structure:

cpp
Copy code
struct Node {
    int data;
    Node* next;  // Pointer to the next node
};
This defines a structure for each node in the linked list, where data stores the value, and 
next points to the next node.

Detect Loop Function:

cpp
Copy code
bool detectLoop(Node* head) {
    Node* slow = head;  // Slow pointer starts at the head
    Node* fast = head;  // Fast pointer starts at the head
slow and fast pointers are initialized at the head of the linked list.
The slow pointer moves one step at a time, and the fast pointer moves two steps at a time.
While Loop:

cpp
Copy code
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;  // Move slow pointer one step
    fast = fast->next->next;  // Move fast pointer two steps
This loop continues until fast reaches the end of the list (nullptr), or until the two pointers 
meet, indicating a loop.
fast moves two steps, and slow moves one step.
Check for Loop:

cpp
Copy code
if (slow == fast) {
    return true;  // Loop detected
}
If at any point the slow pointer and the fast pointer meet, that means there is a cycle,
 and the function returns true.
Return False if No Loop:

cpp
Copy code
return false;  // No loop detected
If fast reaches the end of the list (nullptr), it means there is no loop.
Helper Function to Create Nodes:

cpp
Copy code
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}
This function creates and returns a new node with a given data value and initializes its 
next pointer to nullptr.
Main Function:

We create a linked list with five nodes, and then manually introduce a loop by pointing the 
next of the last node to the second node.
The detectLoop() function is called, and it prints whether a loop was detected.
Example:
Consider this linked list without a loop:

rust
Copy code
10 -> 20 -> 30 -> 40 -> 50 -> nullptr
The fast pointer will reach nullptr, indicating no loop.

Now, let's introduce a loop where 50 -> next points back to 20:

rust
Copy code
10 -> 20 -> 30 -> 40 -> 50
        ^                |
        |----------------|
In this case, the slow and fast pointers will eventually meet at some node in the loop,
 and the function will return true, indicating a loop is detected.

Time Complexity:
O(n) where n is the number of nodes in the linked list. Both pointers move at most n steps 
before either detecting a loop or reaching the end of the list.
Space Complexity:
O(1) as we are using only two pointers and not any additional data structures.
*/