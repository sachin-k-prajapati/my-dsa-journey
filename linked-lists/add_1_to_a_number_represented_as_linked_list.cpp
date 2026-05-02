/*
Problem: Add 1 to a Linked List Number
Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Definition:
Given a linked list where each node represents a digit,
the list forms a number.

Add 1 to that number and return updated list.

Example:

4 → 5 → 6  → represents 456  
After +1 → 457 → 4 → 5 → 7  

------------------------------------------------------------

Approach:

We cannot traverse backwards in linked list,
so we reverse the list first.

Steps:

1. Reverse the linked list
2. Add 1 (handle carry like addition)
3. Reverse back while reconstructing
4. If carry remains → add new node

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Deep Intuition:

Addition always starts from rightmost digit.

But in linked list:
we only have forward access

So:

Reverse → process like normal addition → restore

------------------------------------------------------------

Example:

1 → 9 → 9

Reverse:
9 → 9 → 1

Add 1:
0 → 0 → 2

Reverse back:
2 → 0 → 0

------------------------------------------------------------

Special Case:

If all digits are 9:

9 → 9 → 9  
→ 1 → 0 → 0 → 0  

------------------------------------------------------------
*/

using namespace std;


struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* addOne(Node* head) {

        // Step 1: Reverse the linked list
        Node* pre = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextNode;
        }

        // Now 'pre' is new head of reversed list
        curr = pre;
        pre = nullptr;

        int carry = 0;

        // Step 2: Add 1 to first node
        if (curr->data == 9) {      // If 9 → becomes 0 and carry continues
            curr->data = 0;
            carry = 1;
        } else {
            curr->data += 1;        // Else → increment and stop carry
        }

        // Step 3: Traverse remaining nodes
        while (curr->next) {

            Node* nextNode = curr->next;

            // Reverse back while traversing
            curr->next = pre;
            pre = curr;
            curr = nextNode;

            // Handle carry
            if (carry == 1) {                   // If carry exists → process current node
                if (curr->data == 9) {      
                    curr->data = 0;
                    carry = 1;
                } else {
                    curr->data += 1;
                    carry = 0;
                }
            }
        }

        // Final link reversal
        curr->next = pre;

        // Step 4: If carry still exists → add new node
        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = curr;
            head = newNode;
        }

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Reverse Linked List + Carry Handling

------------------------------------------------------------

Core Idea:

Reverse → Add → Reverse back

------------------------------------------------------------

Why reverse?

Because addition happens from least significant digit

------------------------------------------------------------

Carry Logic:

If digit = 9 → becomes 0 and carry continues

Else:
increment and stop carry

------------------------------------------------------------

Edge Case:

All digits = 9

→ need extra node at front

------------------------------------------------------------

Common Mistakes:

❌ Forgetting to reverse back
❌ Incorrect carry propagation
❌ Missing new node creation
❌ Losing list links

------------------------------------------------------------

Interview Line:

"Reverse the list, perform addition with carry,
then reverse back."

------------------------------------------------------------

Mental Shortcut:

Reverse → Add → Restore

------------------------------------------------------------
*/