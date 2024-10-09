//Intersection Point of two Linked Lists.
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

// Function to get the length of a linked list
int getLength(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection node of two linked lists
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Step 1: Get the lengths of both linked lists
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Step 2: Align the starting points by advancing the longer list by the difference in lengths
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Step 3: Traverse both lists together until an intersection is found
    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) { // Intersection found
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    // No intersection found
    return nullptr;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example of creating two linked lists with an intersection
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = headA; // Intersection at node with value 1 // it means 6-7-1-2-3-4-5  L=7

    ListNode* headC = new ListNode(8);
    headC->next = new ListNode(9);
    headC->next->next = new ListNode(1);
    // Finding the intersection point
    ListNode* intersection = getIntersectionNode(headA, headB);
    
    if (intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

     ListNode* intersection1 = getIntersectionNode(headA, headC);
    
    if (intersection1 != nullptr) {
        cout << "Intersection at node with value: " << intersection1->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }


    return 0;
}
//Even though both lists have nodes with the same value 0, they are distinct nodes stored in
//  different memory locations. Therefore, the lists do not intersect.

// The algorithm is designed to detect when two linked lists share nodes in memory, and it would 
// return nullptr in this case, indicating no intersection.