// Merge Sort For Linked lists
/*
Let's break down the **`mergeSort`** and **`sortedMerge`** functions with an example and walk
 through the process step by step.

### Functions Overview:

1. **`mergeSort(Node** head)`**:
   - This function divides the linked list into two halves, recursively applies the merge sort
    to both halves, and then merges the two sorted halves.

2. **`sortedMerge(Node* a, Node* b)`**:
   - This function merges two sorted linked lists into one sorted list by comparing the nodes.

### Example:

Suppose we have the following unsorted linked list:

```
20 -> 3 -> 15 -> 5 -> 10 -> 2
```

**Goal**: Sort this linked list using merge sort.

### Step-by-Step Execution:

#### 1. **Initial Call to `mergeSort`**:

We start by calling `mergeSort(&head)`, where the head of the list points to `20`.

The linked list is:

```
20 -> 3 -> 15 -> 5 -> 10 -> 2
```

- **Finding the middle**: The `getMiddle` function finds the middle node. Using the slow and
fast pointer technique, it splits the list into two halves:
  - First half: `20 -> 3 -> 15`

  - Second half: `5 -> 10 -> 2`

#### 2. **Recursive Sorting of the First Half**:

We now recursively apply `mergeSort` to the first half: `20 -> 3 -> 15`.

- **Finding the middle**: The list is split into two halves:
  - First half: `20`
  - Second half: `3 -> 15`

- Now we recursively apply `mergeSort` to both halves:

  - For the list `20`, no further division is needed since it has only one element. So, we
   return this as a sorted list.

  - For the list `3 -> 15`, we split it into:
    - First half: `3`
    - Second half: `15`

  - Again, no further division is needed since both lists have only one element. We now merge
   the two sorted halves `3` and `15`.

#### 3. **Merging the Two Halves (`3` and `15`)**:

We call `sortedMerge(a, b)` where:
- `a = 3`
- `b = 15`

- **Comparing the values**: We compare `3` and `15`. Since `3 <= 15`, we add `3` to the result
 list. Now, we recursively merge the remaining list `nullptr` (end of the first list) with `15`.

- **Result**: The merged list is `3 -> 15`.

Now, we merge the two sorted halves: `20` and `3 -> 15`.

#### 4. **Merging the Two Halves (`20` and `3 -> 15`)**:

We call `sortedMerge(a, b)` where:
- `a = 20`
- `b = 3 -> 15`

- **Comparing the values**: We compare `20` and `3`. Since `3 <= 20`, we add `3` to the result
 list. Now, we recursively merge `20` with `15`.

- **Next comparison**: We compare `20` and `15`. Since `15 <= 20`, we add `15` to the result
list. Now, we recursively merge `20` with `nullptr` (end of the second list).

- **Result**: The merged list is `3 -> 15 -> 20`.

#### 5. **Recursive Sorting of the Second Half**:

Now, we recursively apply `mergeSort` to the second half: `5 -> 10 -> 2`.

- **Finding the middle**: The list is split into:
  - First half: `5`
  - Second half: `10 -> 2`

- Now, we recursively apply `mergeSort` to both halves:

  - For the list `5`, no further division is needed since it has only one element.

  - For the list `10 -> 2`, we split it into:
    - First half: `10`
    - Second half: `2`

  - Now we merge the two sorted halves `10` and `2`.

#### 6. **Merging the Two Halves (`10` and `2`)**:

We call `sortedMerge(a, b)` where:
- `a = 10`
- `b = 2`

- **Comparing the values**: We compare `10` and `2`. Since `2 <= 10`, we add `2` to the
result list. Now, we recursively merge `10` with `nullptr`.

- **Result**: The merged list is `2 -> 10`.

Now, we merge the two sorted halves: `5` and `2 -> 10`.

#### 7. **Merging the Two Halves (`5` and `2 -> 10`)**:

We call `sortedMerge(a, b)` where:
- `a = 5`
- `b = 2 -> 10`

- **Comparing the values**: We compare `5` and `2`. Since `2 <= 5`, we add `2` to the result
list. Now, we recursively merge `5` with `10`.

- **Next comparison**: We compare `5` and `10`. Since `5 <= 10`, we add `5` to the result list.
 Now, we recursively merge `nullptr` with `10`.

- **Result**: The merged list is `2 -> 5 -> 10`.

#### 8. **Final Merge of the Two Halves**:

Now, we merge the two sorted halves: `3 -> 15 -> 20` and `2 -> 5 -> 10`.

We call `sortedMerge(a, b)` where:
- `a = 3 -> 15 -> 20`
- `b = 2 -> 5 -> 10`

- **Comparing the values**: We compare `3` and `2`. Since `2 <= 3`, we add `2` to the result
list. Now, we recursively merge `3 -> 15 -> 20` with `5 -> 10`.

- **Next comparison**: We compare `3` and `5`. Since `3 <= 5`, we add `3` to the result list.
 Now, we recursively merge `15 -> 20` with `5 -> 10`.

- **Next comparison**: We compare `15` and `5`. Since `5 <= 15`, we add `5` to the result list.
 Now, we recursively merge `15 -> 20` with `10`.

- **Next comparison**: We compare `15` and `10`. Since `10 <= 15`, we add `10` to the result
list. Now, we recursively merge `15 -> 20` with `nullptr`.

- **Result**: The merged list is `2 -> 3 -> 5 -> 10 -> 15 -> 20`.

### Final Sorted List:

```
2 -> 3 -> 5 -> 10 -> 15 -> 20
```

This is the sorted linked list obtained after applying merge sort.

### Conclusion:

- **`mergeSort`** divides the list into halves until it reaches lists of size 1.
- **`sortedMerge`** combines two sorted linked lists by comparing elements step-by-step and
 forming a merged sorted list.
*/
#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
};

// Utility function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert a new node at the head of the list
void push(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to split the linked list into two halves
Node* getMiddle(Node* head) {
    if (head == nullptr) return head;
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* sortedMerge(Node* a, Node* b) {//sort and then conquere
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Main merge sort function for linked list // divide 
void mergeSort(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return;

    Node* middle = getMiddle(*head);
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    // Recursively apply merge sort to both halves
    mergeSort(head);
    mergeSort(&nextToMiddle);

    // Merge the two sorted halves
    *head = sortedMerge(*head, nextToMiddle);//sort and then conquere
}

int main() {
    Node* head = nullptr;

    // Example linked list
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);

    cout << "Linked List before sorting: ";
    printList(head);

    mergeSort(&head);

    cout << "Linked List after sorting: ";
    printList(head);

    return 0;
}
