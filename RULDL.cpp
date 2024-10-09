// Remove Duplicates in a Un-sorted Linked List.

// To remove duplicates from an unsorted linked list, we can use a hashing technique.
// We traverse the list and store each encountered value in a set. If we find a value
// that already exists in the set, we remove that node from the linked list.

#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node *head)
{
    if (head == nullptr)
        return;

    unordered_set<int> seen; // Set to store seen values
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        // If current node's data is already in the set, remove the node
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next; // Skip the current node
            delete current;             // Free the memory of the duplicate node
        }
        else
        {
            seen.insert(current->data); // Insert the current node's data into the set
            prev = current;             // Move the previous pointer to the current node
        }
        current = prev->next; // Move to the next node
    }
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(10);

    cout << "Original List: ";
    printList(head);

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
/*In C++, seen.end() is a function in the unordered_set class that returns an iterator
pointing to a position past the last element of the set. This is known as the "end" iterator.

Key Points:
end() doesn't point to any actual element in the set. Instead, it signifies the position after
the last valid element.
Purpose: It is commonly used to signal that an element was not found when searching in the set.
 If an element isn't found, the find() function returns this special "end" iterator.*/