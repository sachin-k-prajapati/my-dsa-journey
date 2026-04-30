/*
Problem: Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/

Definition:
Given the head of a linked list,
return the node where the cycle begins.

If no cycle exists → return NULL.

------------------------------------------------------------

Approach:

This is an extension of Floyd’s Cycle Detection Algorithm.

We do it in 2 phases:

Phase 1 → Detect cycle
Phase 2 → Find starting node of cycle

------------------------------------------------------------

Phase 1: Detect Cycle

Use two pointers:

slow → moves 1 step
fast → moves 2 steps

If they meet → cycle exists

If fast reaches NULL → no cycle

------------------------------------------------------------

Phase 2: Find Cycle Start

After collision:

Move one pointer (fast) to head

Keep other pointer (slow) at meeting point

Now move both one step at a time

Where they meet again → THAT is the cycle start

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

No extra memory used.

------------------------------------------------------------

Deep Intuition (VERY IMPORTANT):

Let:

L = distance from head to cycle start  
C = cycle length  
x = distance from cycle start to meeting point  

When slow and fast meet:

2 * (L + x) = L + x + kC

Simplifying:

L + x = kC  
=> L = kC - x  

Which means:

If one pointer starts from head
and another from meeting point

they will meet at cycle start

------------------------------------------------------------

Example:

1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←

They meet somewhere in loop

Reset one pointer to head

Move both → meet at node 3 (cycle start)

------------------------------------------------------------
*/

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // Phase 1: Detect cycle using slow & fast
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {

            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            // If they meet → cycle exists
            if (slow == fast) break;
        }

        // No cycle case
        if (!fast || !fast->next) return nullptr;

        // Phase 2: Find starting node of cycle

        // Move one pointer to head
        fast = head;

        // Move both pointers one step
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Meeting point is cycle start
        return fast;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Floyd’s Cycle Detection + Mathematical Insight

Steps:

1. Detect cycle (slow & fast)
2. Reset one pointer to head
3. Move both one step
4. Meeting point = cycle start

Most Important Insight:

L = kC - x

This guarantees meeting at cycle start

------------------------------------------------------------

Common Mistakes:

❌ Not checking (fast && fast->next)
❌ Returning meeting point instead of cycle start
❌ Forgetting to reset pointer to head

------------------------------------------------------------

Interview Line:

"Use Floyd’s algorithm to detect cycle,
then reset one pointer to head and
move both pointers to find cycle start."

------------------------------------------------------------

Mental Shortcut:

Detect → Reset → Move → Meet

------------------------------------------------------------
*/