/*
Problem: Remove Nth Node From End of List
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Definition:
Given the head of a linked list,
remove the nth node from the end.

Return the updated head.

------------------------------------------------------------

Approach 1: Two Pass (Count + Remove)

Steps:

1. Traverse list and count total nodes
2. Find position from start:
   position = length - n
3. Traverse again to that node
4. Remove it

------------------------------------------------------------

Approach 2: One Pass (Optimal - Two Pointer)

Use two pointers:

fast → moves n steps ahead
slow → starts from head

Then move both together:

When fast reaches end,
slow is just before node to delete

------------------------------------------------------------

Key Points:

Time Complexity:
O(N)

Space Complexity:
O(1)

------------------------------------------------------------

Deep Intuition:

We maintain a gap of n nodes
between fast and slow.

So when fast reaches end,
slow automatically reaches
(node before deletion)

------------------------------------------------------------

Example:

1 → 2 → 3 → 4 → 5
n = 2

After moving fast 2 steps:

slow at 1
fast at 3

Move both:

slow → 2 → 3
fast → 4 → 5

Now slow is at node before 4

Remove 4

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
// Solution 1: Two Pass Approach (Your Logic)
// ============================================================

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        ListNode* slowp = head;

        int count = 1;
        int slow = 0;

        // Edge case: single node
        if (!head->next && n == 1) {
            delete head;
            return head = nullptr;
        }

        while (temp) {

            temp = temp->next;
            count++;

            // When temp reaches last node
            if (!temp->next) {

                slow = count - n;

                // Remove head
                if (slow == 0) {
                    head = slowp->next;
                    delete slowp;
                    break;
                }

                // Move to node before deletion
                while (--slow) {
                    slowp = slowp->next;
                }

                // Remove node
                ListNode* rmv = slowp->next;
                slowp->next = rmv->next;
                delete rmv;
                break;
            }
        }

        return head;
    }
};



/*
------------------------------------------------------------
Solution 2: One Pass (Optimal - Two Pointer)
------------------------------------------------------------
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast n steps ahead
        int i = 0;
        while (i < n) {
            fast = fast->next;
            i++;
        }

        // If fast becomes NULL,
        // remove head node
        if (!fast) return head->next;

        // Move both pointers together
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove target node
        ListNode* rmv = slow->next;
        slow->next = rmv->next;
        delete rmv;

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Two Pointer (Fast & Slow)

------------------------------------------------------------

Two Pass Idea:

Count nodes → find index → delete

------------------------------------------------------------

One Pass Idea (IMPORTANT):

Maintain gap of n nodes

------------------------------------------------------------

Core Trick:

fast moves n steps first

Then move both until fast reaches end

------------------------------------------------------------

Edge Case:

If fast == NULL after moving n steps
→ remove head

------------------------------------------------------------

Common Mistakes:

❌ Not handling head removal
❌ Off-by-one errors
❌ Incorrect pointer movement

------------------------------------------------------------

Interview Line:

"Use two pointers with a gap of n
to remove node in one pass."

------------------------------------------------------------

Mental Shortcut:

Gap → Move → Delete

------------------------------------------------------------
*/