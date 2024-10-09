//Count triplets in a sorted DLL whose sum is equal to given value “X”.
#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

int countTriplets(Node* head, int X) {
    // Count of triplets
    int count = 0;

    // Pointer for first element
    for (Node* first = head; first != nullptr; first = first->next) {
        // Initialize second and third pointers
        Node* second = first->next;
        Node* third = head;

        // Move third to the end of the list
        while (third->next != nullptr) {
            third = third->next;
        }

        // Check pairs for each first
        while (second != nullptr && third != nullptr && second != third && second->prev != third) {
            int sum = first->data + second->data + third->data;

            if (sum == X) {
                count++;
                second = second->next;  // Move second pointer forward
                third = third->prev;     // Move third pointer backward
            } else if (sum < X) {
                second = second->next; // Increase sum by moving second pointer
            } else {
                third = third->prev; // Decrease sum by moving third pointer
            }
        }
    }

    return count;
}

// Example usage
int main() {
    // Create a sorted doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    int X = 6; // Example sum to find
    int result = countTriplets(head, X);
    std::cout << "Count of triplets with sum " << X << " is: " << result << std::endl;

    // Clean up memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
