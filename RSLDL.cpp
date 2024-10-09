// Remove Duplicates in a sorted Linked List.

// To remove duplicates from a sorted linked list, you can traverse the list and compare
//  each node with the next one. If they are the same, you skip the duplicate node. Here's
//   a simple implementation in C++:

#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(Node *head)
{
    Node *current = head; // Start with the head of the linked list

    while (current != nullptr && current->next != nullptr)
    {
        if (current->data == current->next->data)
        {                                    // Check if current node is the same as the next node
            Node *duplicate = current->next; // Store the duplicate node
            current->next = duplicate->next; // Skip the duplicate node
            delete duplicate;                // Free the memory of the duplicate node
        }
        else
        {
            current = current->next; // Move to the next node
        }
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    std::cout << "Original list: ";
    printList(head);

    removeDuplicates(head); // Remove duplicates

    std::cout << "List after removing duplicates: ";
    printList(head);

    // Cleanup (deleting the remaining nodes)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
