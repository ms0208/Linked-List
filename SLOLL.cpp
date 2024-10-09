// Find the starting point of the loop. 
#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *findLoopStart(Node *head)
{
    if (!head || !head->next)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Cycle detected
            break;
        }
    }

    // No cycle
    if (slow != fast)
        return nullptr;

    // Step 2: Find the starting point of the loop
    slow = head; // Reset slow to head
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Both pointers meet at the start of the loop
    return slow;
}

// Helper function to create a loop for testing
void createLoop(Node *head, int pos)
{
    Node *loopNode = head;
    for (int i = 0; i < pos; i++)
    {
        loopNode = loopNode->next;
    }
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = loopNode;
}

// Example usage
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop for testing (pointing 5 to 1)
    createLoop(head, 0);

    Node *loopStart = findLoopStart(head);
    if (loopStart)
    {
        std::cout << "Loop starts at node with data: " << loopStart->data << std::endl;
    }
    else
    {
        std::cout << "No loop detected." << std::endl;
    }

    return 0;
}
