//Pair sum of doubly linked list
#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a new node at the end of the doubly linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp; // Link the new node back to the previous node
    }
}

// Function to find pairs with a given sum in the doubly linked list
void findPairsWithSum(Node* head, int targetSum) {
    unordered_set<int> seen; // To store the values we have seen
    Node* curr = head;

    while (curr != nullptr) {
        int complement = targetSum - curr->data;

        // Check if the complement exists in the set
        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: (" << curr->data << ", " << complement << ")\n";
        }

        // Add the current node's data to the set
        seen.insert(curr->data);
        curr = curr->next; // Move to the next node
    }
}

// Function to display the doubly linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to demonstrate finding pairs with a given sum
int main() {
    Node* head = nullptr; // Initialize the doubly linked list

    // Insert some nodes into the doubly linked list
    insert(head, 10);
    insert(head, 15);
    insert(head, 3);
    insert(head, 7);
    insert(head, 8);
    insert(head, 5);

    cout << "Doubly Linked List: ";
    display(head); // Display the list

    int targetSum = 10; // Define the target sum
    cout << "Finding pairs with sum " << targetSum << ":\n";
    findPairsWithSum(head, targetSum); // Find and display pairs with the given sum

    return 0;
}
