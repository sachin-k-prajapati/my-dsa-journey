/*
========================================================
876. Middle of the Linked List
========================================================

Problem:
Given the head of a singly linked list,
return the middle node of the linked list.

Important:
-> If there are two middle nodes,
   return the SECOND middle node.

--------------------------------------------------------
Example 1:

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
3 -> 4 -> 5

Explanation:
Middle node is 3

--------------------------------------------------------
Example 2:

Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Output:
4 -> 5 -> 6

Explanation:
There are two middle nodes:
3 and 4

We return the second one → 4

--------------------------------------------------------
Optimal Approach:
Slow and Fast Pointer (Tortoise and Hare)

Use two pointers:

1. slow -> moves 1 step at a time
2. fast -> moves 2 steps at a time

Why?

When fast reaches the end,
slow will be standing at the middle.

--------------------------------------------------------
Dry Run:

List:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Initially:

slow = 1
fast = 1

Step 1:

slow = 2
fast = 3

Step 2:

slow = 3
fast = 5

Step 3:

slow = 4
fast = NULL

Loop stops

Answer = slow = 4

Correct (second middle)

--------------------------------------------------------
Why This Works:

Since fast moves twice as fast as slow:

When fast completes the list,
slow reaches halfway point.

For even length lists,
slow naturally lands on second middle.

--------------------------------------------------------
Time Complexity:

O(n)

Each node is visited at most once.

--------------------------------------------------------
Space Complexity:

O(1)

No extra space used.

--------------------------------------------------------
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;

    // Default constructor
    ListNode() {
        val = 0;
        next = nullptr;
    }

    // Constructor with value
    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    // Constructor with value + next pointer
    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Slow pointer moves 1 step
        ListNode* slow = head;

        // Fast pointer moves 2 steps
        ListNode* fast = head;

        // Continue until fast reaches end
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow now points to middle node
        return slow;
    }
};