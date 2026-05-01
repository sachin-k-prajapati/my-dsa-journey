/*
Problem: Delete the Middle Node of a Linked List
Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

Definition:
Given the head of a linked list,
delete the middle node and return the updated list.

Middle is defined as:
⌊n / 2⌋ (0-based index)

Examples:

n = 1 → remove index 0  
n = 2 → remove index 1  
n = 5 → remove index 2  

------------------------------------------------------------

Approach:

Use slow & fast pointer technique.

Goal:
Find the middle node and remove it.

------------------------------------------------------------

Approach 1: Your Conditional Handling

You are manually handling edge cases
while moving fast pointer.

This approach works but is complex.

------------------------------------------------------------

Approach 2: Clean Optimal Solution

Steps:

1. Use slow & fast pointers
2. Maintain previous pointer (preSlow)
3. When fast reaches end:
   slow is at middle
4. Remove slow node using preSlow

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Deep Intuition:

Fast moves 2 steps
Slow moves 1 step

So:

When fast reaches end,
slow reaches middle

To delete node:

We need previous pointer:

preSlow → slow → next

Delete slow:
preSlow->next = slow->next

------------------------------------------------------------

Example:

1 → 3 → 4 → 7 → 1 → 2 → 6

slow ends at 7

Remove it:

1 → 3 → 4 → 1 → 2 → 6

------------------------------------------------------------
*/

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// ============================================================
// Solution 1: Your Conditional Logic (as provided)
// ============================================================

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Single node case
        if (!head->next) return head = nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next && fast->next->next) {

            // Special case handling
            if (!fast->next->next->next) {
                slow->next = slow->next->next;
                return head;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        // Remaining edge handling
        if (!fast->next) {
            slow->next = slow->next->next;
        } 
        else if (!fast->next->next) {
            slow->next = slow->next->next;
        }

        return head;
    }
};



/*
------------------------------------------------------------
Solution 2: Optimal Clean Approach
------------------------------------------------------------
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // If only one node → result becomes empty
        if (!head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // To track node before slow
        ListNode* preSlow;

        while (fast && fast->next) {

            preSlow = slow;

            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps
        }

        // Remove middle node
        preSlow->next = slow->next;
        delete slow;

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Slow & Fast Pointer

------------------------------------------------------------

Core Idea:

Fast moves twice as fast

So when fast reaches end,
slow is at middle

------------------------------------------------------------

Why preSlow?

Because singly linked list
cannot go backward

We need previous node to delete

------------------------------------------------------------

Edge Case:

Single node:
return NULL

------------------------------------------------------------

Common Mistakes:

❌ Forgetting preSlow
❌ Wrong middle detection
❌ Memory leak (not deleting node)
❌ Not handling single node

------------------------------------------------------------

Interview Line:

"Use slow-fast pointers to find middle,
track previous node to delete it."

------------------------------------------------------------

Mental Shortcut:

Find Mid → Track Prev → Delete

------------------------------------------------------------
*/