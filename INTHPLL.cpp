// insert nth position in a linked list
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(NULL) {}
};

// Function to insert a node at the nth position
Node* insertAtNthPosition(Node* head, int data, int n) {
    // Create a new node with the given data
    Node* newNode = new Node(data);

    // If inserting at the head (position 1)
    if (n == 1) {
        newNode->next = head;
        return newNode;
    }

    // Traverse the linked list to find the (n-1)th node
    Node* current = head;
    for (int i = 1; i < n - 1; i++) {
        if (current == NULL) {
            cout << "Position out of bounds" << endl;
            return head;  // Invalid position
        }
        current = current->next;
    }

    // Insert the new node at the nth position
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    int data, n;
    cout << "Enter number to insert: ";
    cin >> data;
    cout << "Enter position to insert at: ";
    cin >> n;

    // Insert the number at the nth position
    head = insertAtNthPosition(head, data, n);

    cout << "List after insertion: ";
    printList(head);

    return 0;
}
