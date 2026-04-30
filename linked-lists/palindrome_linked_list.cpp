/*
Problem: Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/

Definition:
Given the head of a singly linked list,
check whether the list is a palindrome.

Palindrome means:
reads same forward and backward

Example:
1 → 2 → 2 → 1 → true
1 → 2 → false

------------------------------------------------------------

Approach:

We solve this in 3 steps:

1. Find middle of linked list
2. Reverse second half
3. Compare both halves

------------------------------------------------------------

Step 1: Find Middle

Use slow & fast pointers:

slow → 1 step  
fast → 2 steps  

When fast reaches end,
slow is at middle

------------------------------------------------------------

Step 2: Reverse Second Half

Start from:
slow->next

Reverse the second half in-place

------------------------------------------------------------

Step 3: Compare

Compare:

first half (head)
second half (reversed)

If any mismatch → false

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Deep Intuition:

Instead of storing values,
we reverse the second half
and compare directly.

This avoids extra space.

Example:

1 → 2 → 2 → 1

Split:

1 → 2   |   2 → 1

Reverse second:

1 → 2   |   1 → 2

Compare:
1 == 1  
2 == 2  

------------------------------------------------------------

Important:

We only compare till second half ends.

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
    bool isPalindrome(ListNode* head) {

        // Single node → always palindrome
        if (!head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* head1 = slow->next;

        ListNode* pre = nullptr;
        ListNode* curr = head1;

        while (curr) {

            // Store next node
            ListNode* nextnode = curr->next;

            // Reverse pointer
            curr->next = pre;

            // Move pointers
            pre = curr;
            curr = nextnode;
        }

        // Step 3: Compare both halves

        while (pre) {

            if (head->val != pre->val) {
                return false;
            }

            head = head->next;
            pre = pre->next;
        }

        return true;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List + Reverse + Two Pointer

Steps:

1. Find middle
2. Reverse second half
3. Compare

------------------------------------------------------------

Why reverse second half?

So we can compare from both ends
without extra space

------------------------------------------------------------

Key Insight:

We don't need full reversal,
only second half is enough

------------------------------------------------------------

Common Mistakes:

❌ Wrong middle detection
❌ Forgetting slow->next start
❌ Incorrect reverse logic
❌ Comparing entire list instead of half

------------------------------------------------------------

Interview Line:

"Find middle, reverse second half,
then compare both halves."

------------------------------------------------------------

Mental Shortcut:

Mid → Reverse → Compare

------------------------------------------------------------
*/