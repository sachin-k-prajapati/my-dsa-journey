/*
Problem: Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/

Definition:
Given the head of a linked list,
determine whether the list contains a cycle.

Cycle means:
while traversing, you visit the same node again.

Return:
true  → cycle exists
false → no cycle

------------------------------------------------------------

Approach 1: Modify Node Values (Not Recommended)

Idea:
- Traverse the list
- Mark visited nodes by changing their value
- If we encounter a marked node again → cycle

BUT:
❌ This modifies the original list
❌ Not allowed in most interviews
❌ Unsafe approach

Only useful for understanding concept,
not for real implementation.

------------------------------------------------------------

Approach 2: Floyd’s Cycle Detection (Tortoise & Hare)

Best and optimal solution.

Idea:

Use two pointers:
slow → moves 1 step
fast → moves 2 steps

If cycle exists:
they will eventually meet.

If no cycle:
fast reaches NULL

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

No extra memory used.

------------------------------------------------------------

Deep Intuition:

Imagine a circular track.

If one person runs faster than another,
they will eventually meet.

Same happens here.

slow = 1 step
fast = 2 steps

If loop exists:
they collide

If no loop:
fast reaches end

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

// ============================================================
// Solution 1: Marking Visited Nodes (Not Recommended)
// ============================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *temp = head;

        while (temp) {

            // Mark current node as visited
            temp->val = 1000000;

            // If next node is already marked → cycle found
            if (temp->next != nullptr && temp->next->val == 1000000) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};



/*
------------------------------------------------------------
Solution 2: Floyd’s Cycle Detection (Optimal)
------------------------------------------------------------
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Edge case
        if (!head) return false;

        // Initialize both pointers
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {

            // Move slow by 1 step
            slow = slow->next;

            // Move fast by 2 steps
            fast = fast->next->next;

            // If they meet → cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches NULL → no cycle
        return false;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Two Pointer (Fast & Slow)

Core Idea:
Fast pointer catches slow pointer
if cycle exists

Why it works:
Fast moves faster → closes gap in loop

Most Important Condition:
while (fast && fast->next)

Common Mistakes:

❌ Forgetting fast->next check
❌ Using extra space unnecessarily
❌ Modifying node values (bad practice)

Interview Line:

"Use Floyd’s cycle detection algorithm
with slow and fast pointers."

Mental Shortcut:

Slow = 1 step
Fast = 2 steps
Meet = Cycle

------------------------------------------------------------
*/