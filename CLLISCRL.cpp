// Check if a linked list is a circular linked list.

// To check whether a linked list is a circular linked list, we need to determine if there is any
// cycle in the list. A circular linked list is one where the last node points back to one of the
// previous nodes (not necessarily the head node).

// A common approach to solving this problem is the Floyd's Cycle Detection Algorithm
//  (also known as the Tortoise and Hare algorithm). It uses two pointers that move at different
//   speeds through the list. If there's a cycle, the two pointers will eventually meet.

// Here’s the C++ code to check if a linked list is circular:

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return false; // An empty list is not circular
    }

    Node *slow = head;
    Node *fast = head;

    // Move slow pointer by one step and fast pointer by two steps
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // slow moves one step
        fast = fast->next->next; // fast moves two steps

        if (slow == fast)
        {
            return true; // If slow meets fast, there's a cycle (circular)
        }
    }

    return false; // If fast reaches the end, the list is not circular
}

int main()
{
    // Example 1: Non-circular list
    Node *head1 = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    head1->next = second;
    second->next = third;
    third->next = fourth;

    cout << "List 1 is " << (isCircular(head1) ? "Circular" : "Not Circular") << endl;

    // Example 2: Circular list
    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = head2; // Making the list circular

    cout << "List 2 is " << (isCircular(head2) ? "Circular" : "Not Circular") << endl;

    return 0;
}
