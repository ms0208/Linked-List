// add 1 in a linked list
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse the linked list
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add 1 to the linked list
Node *addOne(Node *head)
{
    // Reverse the linked list to add from least significant digit
    head = reverseList(head);

    Node *current = head;
    int carry = 1; // Start with adding 1

    // Traverse the list to add 1
    while (current != NULL)
    {
        int sum = current->data + carry;
        carry = sum / 10;
        current->data = sum % 10;

        // Move to the next node
        if (carry == 0)
            break; // No more carry to propagate
        if (current->next == NULL && carry > 0)
        {
            current->next = new Node(carry); // Add a new node for carry
            carry = 0;
        }
        current = current->next;
    }

    // Reverse the list back to restore the original order
    return reverseList(head);
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list representing the number 129
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);

    cout << "Original number: ";
    printList(head);

    // Add 1 to the number
    head = addOne(head);

    cout << "After adding 1: ";
    printList(head);

    return 0;
}
/*
Let's walk through the example step-by-step using the linked list representation of `129`. 
We will add `1` to this number and demonstrate how the carry is handled.

### Initial Linked List:
```
1 -> 2 -> 9
```

### Step 1: Reverse the Linked List
We reverse the linked list to simplify the addition process:
```
9 -> 2 -> 1
```

Now, we will start adding `1` from the least significant digit, which is the first node in the 
reversed list (`9`).

### Step 2: Add `1` to the Reversed List
We traverse through the reversed linked list and add `1`, handling the carry at each step:

#### 1st Node (Digit `9`):
- Current node value: `9`
- Add `carry` (`1`): `9 + 1 = 10`
- New value of the node: `10 % 10 = 0` (we set the node's data to `0`)
- Carry: `10 / 10 = 1` (carry is propagated to the next node)

The updated linked list becomes:
```
0 -> 2 -> 1
```

#### 2nd Node (Digit `2`):
- Current node value: `2`
- Add carry (`1`): `2 + 1 = 3`
- New value of the node: `3 % 10 = 3` (we set the node's data to `3`)
- Carry: `3 / 10 = 0` (no carry is propagated)

The updated linked list becomes:
```
0 -> 3 -> 1
```

Since there is no carry left, we continue without changes for the remaining nodes.

#### 3rd Node (Digit `1`):
- Current node value: `1`
- No carry left, so the value remains unchanged: `1`

The updated linked list remains:
```
0 -> 3 -> 1
```

### Step 3: Reverse the List Again
After performing the addition, we reverse the list again to restore the correct order:
```
1 -> 3 -> 0
```

### Final Linked List:
```
1 -> 3 -> 0
```
This linked list represents the number `130`, which is the result of adding `1` to `129`.

### Summary of Steps:

1. Reverse the original linked list `1 -> 2 -> 9` to get `9 -> 2 -> 1`.
2. Add `1` to the reversed list:
   - `9 + 1 = 10`, store `0` and carry `1`.
   - `2 + 1 = 3`, store `3` and carry `0`.
   - No change to the `1` node since the carry is `0`.
3. Reverse the updated list `0 -> 3 -> 1` to get `1 -> 3 -> 0`.
4. The final result is `130`.
*/