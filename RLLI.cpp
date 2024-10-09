// Reverse a linked list uing Iteration.
#include <iostream>
using namespace std;

class RL
{
public:
    int data;
    RL *next;

    RL(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
RL* RLL(RL *head)
{
    RL *curr = head, *prev = nullptr, *next;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printList(RL* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    RL* head = new RL(1);
    head->next = new RL(2);
    head->next->next = new RL(3);
    head->next->next->next = new RL(4);
    head->next->next->next->next = new RL(5);

    cout << "Given Linked list:";
    printList(head);

    head = RLL(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}