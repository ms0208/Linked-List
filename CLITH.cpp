//Split a Circular linked list into two halves.
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to split a circular linked list into two halves
void splitList(Node* head, Node** head1, Node** head2) {
    // If the list is empty, return
    if (head == nullptr) return;

    Node *slow = head;
    Node *fast = head;

    // Traverse the list with 'slow' moving one step at a time, and 'fast' moving two steps
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 'slow' is now at the middle of the list

    // If there are an even number of nodes, move 'fast' one step further
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Set the head pointers for the two halves
    *head1 = head;
    *head2 = slow->next;

    // Make the first half circular
    slow->next = *head1;

    // Make the second half circular
    fast->next = *head2;
}

// Function to insert a node at the end of the circular linked list
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to print a circular linked list
void printList(Node* head, const string& listName) {
    if (head == nullptr) return;

    Node* temp = head;
    cout << listName << ": ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);  // Stop when the loop reaches the head again
    cout << "(back to " << head->data << ")" << endl;  // Indicate it's circular
}

int main() {
    Node* head = nullptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Inserting elements in the circular linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    // Split the list
    splitList(head, &head1, &head2);

    // Print both halves
    cout << "First half: ";
    printList(head1,"first");
    cout << "Second half: ";
    printList(head2,"second");

    return 0;
}
