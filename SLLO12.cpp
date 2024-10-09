// Sort a LL of 0's, 1's and 2's
// To sort a linked list containing only 0's, 1's, and 2's, we can use a three-pointer approach.
//  This technique, often referred to as the Dutch National Flag algorithm, ensures that we
//   traverse the list in a single pass, keeping the time complexity at O(n) and space complexity
//    at O(1). Here’s how it works:

#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void sortLinkedList(Node *&head)
{
    if (!head)
        return; // Check if the list is empty

    Node *zeroHead = nullptr, *zeroTail = nullptr;
    Node *oneHead = nullptr, *oneTail = nullptr;
    Node *twoHead = nullptr, *twoTail = nullptr;

    Node *current = head; // Start from the head of the linked list

    // Traverse the linked list and partition nodes into 0s, 1s, and 2s
    while (current)
    {
        if (current->data == 0)
        {
            // Add to 0's list
            if (!zeroHead)
            {
                zeroHead = current;
                zeroTail = zeroHead;
            }
            else
            {
                zeroTail->next = current;
                zeroTail = zeroTail->next;
            }
        }
        else if (current->data == 1)
        {
            // Add to 1's list
            if (!oneHead)
            {
                oneHead = current;
                oneTail = oneHead;
            }
            else
            {
                oneTail->next = current;
                oneTail = oneTail->next;
            }
        }
        else
        {
            // Add to 2's list
            if (!twoHead)
            {
                twoHead = current;
                twoTail = twoHead;
            }
            else
            {
                twoTail->next = current;
                twoTail = twoTail->next;
            }
        }
        current = current->next; // Move to the next node
    }

    // Connect the three lists
    if (zeroTail)
    {
        zeroTail->next = oneHead; // Connect 0's list to 1's list
    }

    if (oneTail)
    {
        oneTail->next = twoHead; // Connect 1's list to 2's list
    }

    if (twoTail)
    {
        twoTail->next = nullptr; // End of the linked list
    }

    // Update head to the new head of the sorted linked list
    head = zeroHead ? zeroHead : (oneHead ? oneHead : twoHead);
}

void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    // Create a linked list: 1 -> 0 -> 2 -> 1 -> 0 -> 2
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(0);
    std::cout << "Original List: ";
    printList(head);

    sortLinkedList(head);

    std::cout << "\nSorted List: ";
    printList(head);

    return 0;
}
