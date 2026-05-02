/*
Problem: Sort a Linked List of 0s, 1s and 2s
Link: https://www.geeksforgeeks.org/problems/sort-a-linked-list-of-0s-1s-and-2s/1

Definition:
Given a linked list where nodes contain only:
0, 1, or 2

Rearrange the list such that:
- all 0s come first
- then all 1s
- then all 2s

------------------------------------------------------------

Approach:

Counting Sort (Two Pass Approach)

Step 1:
Traverse the list and count:
- number of 0s
- number of 1s
- number of 2s

Step 2:
Overwrite the linked list values in order:
- first all 0s
- then all 1s
- then all 2s

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

No extra list created
Only values are modified

------------------------------------------------------------

Deep Intuition:

We are NOT changing links.

Instead:
We are simply rewriting values.

This works because:
Values are limited to only 0, 1, 2

So instead of complex pointer manipulation,
we use counting → then rebuild values.

------------------------------------------------------------

Example:

1 → 2 → 2 → 1 → 2 → 0

Count:
0 → 1
1 → 2
2 → 3

Rebuild:

0 → 1 → 1 → 2 → 2 → 2

------------------------------------------------------------
*/

using namespace std;

/* Node is defined as
*/
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* segregate(Node* head) {

        // Edge case: single node
        if (!head->next) return head;

        // Step 1: Count 0s, 1s, and 2s
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        Node* temp = head;

        while (temp) {

            if (temp->data == 0) count0++;
            else if (temp->data == 1) count1++;
            else count2++;

            temp = temp->next;
        }

        // Step 2: Overwrite values
        temp = head;

        while (count0 + count1 + count2) {

            if (count0) {
                temp->data = 0;
                count0--;
            }
            else if (count1) {
                temp->data = 1;
                count1--;
            }
            else {
                temp->data = 2;
                count2--;
            }

            temp = temp->next;
        }

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Counting Sort on Linked List

------------------------------------------------------------

Core Idea:

Count → Rewrite

------------------------------------------------------------

Why it works:

Values are limited (0,1,2)

So sorting becomes trivial

------------------------------------------------------------

Alternative Approach (Important for interviews):

Using 3 dummy lists:

- one for 0s
- one for 1s
- one for 2s

Then connect them

(This avoids modifying node values)

------------------------------------------------------------

Common Mistakes:

❌ Forgetting second pass
❌ Not resetting temp pointer
❌ Wrong condition in loop

------------------------------------------------------------

Interview Line:

"Use counting sort since values are limited,
or use 3 dummy lists for stable separation."

------------------------------------------------------------

Mental Shortcut:

Count → Rewrite

------------------------------------------------------------
*/