// Find the middle Element of a linked list.

// To find the middle element of a linked list, you can use the "two-pointer"
// approach, where one pointer moves one step at a time (slow pointer), and the other
//  moves two steps at a time (fast pointer). When the fast pointer reaches the end of the list,
//   the slow pointer will be at the middle.

// Here is the C++ code to find the middle element of a singly linked list:

#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize the node with data and next pointer
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to find the middle element of the linked list
Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return nullptr; // Handle edge case: empty list

    Node *slow = head; // Slow pointer that moves one step at a time
    Node *fast = head; // Fast pointer that moves two steps at a time

    // Traverse the list until fast pointer reaches the end
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Move slow by one step
        fast = fast->next->next; // Move fast by two steps
    }

    return slow; // Slow pointer will be at the middle
}

// Function to insert a node at the end of the linked list
void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr;

    // Insert some elements into the linked list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);

    cout << "Linked List: ";
    printList(head);

    // Find the middle element
    Node *middle = findMiddle(head);
    if (middle != nullptr)
    {
        cout << "Middle Element: " << middle->data << endl;
    }

    return 0;
}
