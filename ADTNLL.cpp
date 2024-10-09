// Add two repesent in a linked list
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two linked lists representing numbers
Node* addTwoNumbers(Node* l1, Node* l2) {
    // Reverse both lists to make addition easier
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node* result = NULL;
    Node* tail = NULL;
    int carry = 0;

    // Add the numbers represented by the linked lists
    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        // Create a new node for the result
        Node* newNode = new Node(sum);
        
        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Reverse the result list to restore the correct order
    result = reverseList(result);
    return result;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First number: 243 (represented as 2 -> 4 -> 3)
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // Second number: 564 (represented as 5 -> 6 -> 4)
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    cout << "First number: ";
    printList(l1);

    cout << "Second number: ";
    printList(l2);

    // Add the two numbers
    Node* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
/*
LL1 = 24
LL2 = 65
R1 = 42
R2 = 56
=> sum = 0
sum = 0 + 4 = 4 ->L1
sum = 4+5 = 9 -> l2
9 = new node -> tail , head
sum = 0 + 2 = 2
sum = 2+6 = 8
9->next = 8(tail)
9->8
result revesed = 8->9
*/