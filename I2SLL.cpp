// intersection of 2 sorted linked list
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
void insert(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the intersection of two sorted linked lists
Node* getIntersection(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data == head2->data) {
            if (result == nullptr) {
                result = new Node();
                result->data = head1->data;
                result->next = nullptr;
                tail = result;
            } else {
                tail->next = new Node();
                tail = tail->next;
                tail->data = head1->data;
                tail->next = nullptr;
            }
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    return result;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements into the first sorted linked list
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 4);
    insert(head1, 6);

    // Insert elements into the second sorted linked list
    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 6);
    insert(head2, 8);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* intersect = getIntersection(head1, head2);

    cout << "Intersection of the two lists: ";
    printList(intersect);

    return 0;
}
