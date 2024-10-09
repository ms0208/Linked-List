// Write a Program to check whether the Singly Linked list is a palindrome or not.
#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to check if the linked list is a palindrome
bool isPalindrome(Node *head)
{
    // If the list is empty or has only one node, it's a palindrome
    if (!head || !head->next)
        return true;

    Node *slow = head;
    Node *fast = head;
    stack<int> stk;

    // Push the first half of the list onto the stack
    while (fast && fast->next)
    {
        stk.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the number of nodes is odd, skip the middle node
    if (fast)
    {
        slow = slow->next;
    }

    // Compare the second half of the list with the stack
    while (slow)
    {
        if (stk.top() != slow->data)
        {
            return false; // Mismatch found, not a palindrome
        }
        stk.pop();
        slow = slow->next;
    }

    return true;
}

// Utility function to insert a node at the end of the list
void append(Node *&head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

int main()
{
    Node *head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
/*
Let's walk through the step-by-step execution of the `isPalindrome` function using the example 
list: `1 -> 2 -> 3 -> 2 -> 1`.

### Function Definition Recap:
```cpp
bool isPalindrome(Node* head)
```
This function checks whether a given singly linked list is a palindrome. A palindrome is a 
sequence that reads the same forward and backward.

### Example Linked List:
```
head -> 1 -> 2 -> 3 -> 2 -> 1 -> nullptr
```

### Step-by-Step Breakdown:

1. **Initial Setup**:
   - The linked list has `5` nodes with the values `1, 2, 3, 2, 1`.
   - We initialize two pointers, `slow` and `fast`, both starting at the head of the list.
   - A stack `stk` is also initialized to store the first half of the linked list values.

   - **Initial pointer positions**:
     ```
     slow -> 1 -> 2 -> 3 -> 2 -> 1 -> nullptr
     fast -> 1 -> 2 -> 3 -> 2 -> 1 -> nullptr
     ```

2. **First while loop: Traverse the first half of the list**:
   This loop moves `slow` one step at a time and `fast` two steps at a time. Each value 
   encountered by `slow` is pushed onto the stack. The loop continues until `fast` reaches 
   the end or `fast->next` becomes `nullptr`.

   - **First iteration**:
     - `slow` moves to the second node (`slow = slow->next`).
     - `fast` moves to the third node (`fast = fast->next->next`).
     - The value of the first node (`1`) is pushed onto the stack.
     ```
     stk = [1]
     slow -> 2 -> 3 -> 2 -> 1 -> nullptr
     fast -> 3 -> 2 -> 1 -> nullptr
     ```

   - **Second iteration**:
     - `slow` moves to the third node (`slow = slow->next`).
     - `fast` moves to the fifth node (`fast = fast->next->next`).
     - The value of the second node (`2`) is pushed onto the stack.
     ```
     stk = [1, 2]
     slow -> 3 -> 2 -> 1 -> nullptr
     fast -> 1 -> nullptr
     ```

   At this point, the `fast` pointer has reached the end of the list. The loop terminates
    because `fast->next == nullptr`.

3. **Skipping the middle element (if necessary)**:
   Since `fast` is not `nullptr`, this indicates that the list has an odd number of nodes.
    To ignore the middle node (`3`), we move `slow` one step forward (`slow = slow->next`).

   ```
   slow -> 2 -> 1 -> nullptr
   ```

4. **Second while loop: Compare the second half of the list with the stack**:
   Now, we compare the values of the second half of the linked list (from `slow` onward) with 
   the values popped from the stack.

   - **First iteration**:
     - The top value of the stack (`2`) is compared with the value of `slow` (`2`).
     - Since they are equal, we pop the stack and move `slow` to the next node.
     ```
     stk = [1]
     slow -> 1 -> nullptr
     ```

   - **Second iteration**:
     - The top value of the stack (`1`) is compared with the value of `slow` (`1`).
     - Since they are equal, we pop the stack and move `slow` to the next node.
     ```
     stk = []
     slow -> nullptr
     ```

   Now, `slow` has reached the end of the list, and the stack is empty.

5. **Return true**:
   Since no mismatches were found and the second half of the list matched the reverse of the 
   first half, the function returns `true`, indicating that the linked list is a palindrome.

### Final Output:
```
The linked list is a palindrome.
```

### Summary:
- The **first while loop** stores the first half of the list in a stack.
- If the list has an odd number of nodes, we skip the middle node.
- The **second while loop** compares the remaining nodes with the values popped from the stack 
(i.e., the reverse of the first half).
- If all values match, the list is a palindrome. Otherwise, it is not.
*/