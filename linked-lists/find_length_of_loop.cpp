/*
Problem: Find Length of Loop in Linked List
Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

Definition:
Given the head of a linked list,
determine if a loop (cycle) exists.

If yes → return number of nodes in the loop  
If no  → return 0

------------------------------------------------------------

Approach:

This is an extension of:

1. Cycle Detection (Floyd’s Algorithm)
2. Then count cycle length

Steps:

1. Use slow & fast pointers to detect cycle
2. If no cycle → return 0
3. If cycle found:
   - keep one pointer fixed
   - move the other pointer until it comes back
   - count steps → loop length

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

No extra memory used.

------------------------------------------------------------

Deep Intuition:

Once slow and fast meet,
we are guaranteed to be inside the cycle.

Now:

Imagine walking inside the loop.

Start from meeting point,
walk until you reach same node again.

Number of steps = cycle length

------------------------------------------------------------

Example:

1 → 2 → 3 → 4 → 5
          ↑     ↓
          ← ← ←

Suppose meeting point = node 4

Traversal:
4 → 5 → 3 → 4

Count = 3

------------------------------------------------------------
*/

using namespace std;

/**
 * Definition for singly-linked list.
 */
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {

        // Step 1: Detect cycle using Floyd’s algorithm
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next) {

            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            // If they meet → cycle exists
            if (slow == fast) break;
        }

        // No cycle case
        if (!fast || !fast->next) return 0;

        // Step 2: Count length of loop

        int count = 1;

        // Move slow one step ahead
        slow = slow->next;

        // Traverse full cycle until back to same node
        while (slow != fast) {
            count++;
            slow = slow->next;
        }

        return count;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Floyd’s Cycle Detection + Cycle Length Count

Steps:

1. Detect cycle
2. If no cycle → return 0
3. If cycle:
   traverse loop once and count nodes

------------------------------------------------------------

Core Logic:

After meeting:

count = 1
move pointer until it comes back

------------------------------------------------------------

Why it works:

Meeting point is guaranteed inside loop

So walking forward will eventually
return to same node

------------------------------------------------------------

Common Mistakes:

❌ Forgetting to move slow before counting
❌ Infinite loop due to wrong condition
❌ Not handling no-cycle case

------------------------------------------------------------

Interview Line:

"After detecting cycle using Floyd’s algorithm,
traverse the loop once to count its length."

------------------------------------------------------------

Mental Shortcut:

Detect → Loop → Count

------------------------------------------------------------
*/