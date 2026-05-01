/*
Problem: Odd Even Linked List
Link: https://leetcode.com/problems/odd-even-linked-list/

Definition:
Given a singly linked list,
rearrange nodes such that:

- All nodes at odd indices come first
- Followed by nodes at even indices

NOTE:
Index is based on position (1-based),
NOT value.

Example:

Input:
1 → 2 → 3 → 4 → 5

Output:
1 → 3 → 5 → 2 → 4

------------------------------------------------------------

Approach:

We maintain two separate chains:

1. Odd index nodes
2. Even index nodes

Then connect them at the end.

------------------------------------------------------------

Steps:

1. Initialize:
   odd = head
   even = head->next

2. Store even head separately
   (to attach later)

3. Traverse:

   odd->next = even->next
   even->next = even->next->next

4. Move pointers forward

5. Finally:
   attach even list after odd list

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Deep Intuition:

We are not creating new nodes,
just rearranging links.

Think like:

Odd chain:
1 → 3 → 5

Even chain:
2 → 4

Final:
1 → 3 → 5 → 2 → 4

------------------------------------------------------------

Important:

We must preserve relative order
inside odd and even groups.

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


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Edge case
        if (!head) return head;

        // Initialize pointers
        ListNode* odd = head;
        ListNode* even = head->next;

        // Save head of even list
        ListNode* oddpoint = odd;
        ListNode* evenpoint = even;

        // Traverse and rearrange links
        while (evenpoint && evenpoint->next) {

            // Link next odd node
            oddpoint->next = evenpoint->next;

            // Link next even node
            evenpoint->next = evenpoint->next->next;

            // Move both pointers forward
            oddpoint = oddpoint->next;
            evenpoint = evenpoint->next;
        }

        // Attach even list after odd list
        oddpoint->next = even;

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List Re-linking

Core Idea:

Split list into:
odd-index nodes + even-index nodes

Then merge them

------------------------------------------------------------

Pointer Flow:

odd → jumps by 2
even → jumps by 2

------------------------------------------------------------

Important Trick:

Store even head
because we need to attach it later

------------------------------------------------------------

Common Mistakes:

❌ Losing even list head
❌ Wrong pointer updates
❌ Not checking even->next condition
❌ Confusing index with value

------------------------------------------------------------

Interview Line:

"Separate odd and even nodes using
two pointers and reconnect at the end."

------------------------------------------------------------

Mental Shortcut:

Split → Traverse → Attach

------------------------------------------------------------
*/