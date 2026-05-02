/*
Problem: Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/

Definition:
You are given two linked lists representing two numbers.

Digits are stored in REVERSE order:
(least significant digit first)

Add the two numbers and return the result as a linked list.

------------------------------------------------------------

Example:

l1 = 2 → 4 → 3   (represents 342)
l2 = 5 → 6 → 4   (represents 465)

Result:
7 → 0 → 8  (represents 807)

------------------------------------------------------------

Approach:

This is similar to normal addition.

We process both lists digit by digit
and maintain a carry.

Steps:

1. Add corresponding digits
2. Add carry
3. Store result digit
4. Update carry
5. Move forward

------------------------------------------------------------

Key Points:

Time Complexity: O(max(N, M))
Space Complexity: O(max(N, M)) (for result list)

------------------------------------------------------------

Deep Intuition:

Since digits are reversed:

we can directly simulate addition
from head to tail.

No need to reverse list.

------------------------------------------------------------

Carry Logic:

sum = a + b + carry

digit = sum % 10
carry = sum / 10

------------------------------------------------------------

Example:

9 → 9 → 9
9 → 9

Step by step:

9+9=18 → 8 carry 1  
9+9+1=19 → 9 carry 1  
9+0+1=10 → 0 carry 1  
0+0+1=1 → 1  

Result:
8 → 9 → 0 → 1

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // First addition
        int sum = (l1->val + l2->val);
        int carry = 0;

        if (sum > 9) {
            carry = 1;
        } else {
            carry = 0;
        }

        sum %= 10;

        // Create head of result list
        ListNode *head = new ListNode(sum);
        ListNode *node = head;

        l1 = l1->next;
        l2 = l2->next;

        // Traverse both lists
        while (l1 && l2) {

            sum = (l1->val + l2->val);
            sum += carry;

            if (sum > 9) {
                carry = 1;
            } else {
                carry = 0;
            }

            sum %= 10;

            ListNode *temp = new ListNode(sum);
            node->next = temp;
            node = temp;

            l1 = l1->next;
            l2 = l2->next;
        }

        // If l1 remains
        while (l1) {

            sum = l1->val + carry;

            if (sum > 9) {
                carry = 1;
            } else {
                carry = 0;
            }

            sum %= 10;

            ListNode *temp = new ListNode(sum);
            node->next = temp;
            node = temp;

            l1 = l1->next;
        }

        // If l2 remains
        while (l2) {

            sum = l2->val + carry;

            if (sum > 9) {
                carry = 1;
            } else {
                carry = 0;
            }

            sum %= 10;

            ListNode *temp = new ListNode(sum);
            node->next = temp;
            node = temp;

            l2 = l2->next;
        }

        // If carry still exists
        if (carry) {
            ListNode *temp = new ListNode(carry);
            node->next = temp;
        }

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List + Digit Addition

------------------------------------------------------------

Core Idea:

Simulate manual addition

------------------------------------------------------------

Important:

Lists are reversed → no need to reverse

------------------------------------------------------------

Carry Rule:

sum = a + b + carry
digit = sum % 10
carry = sum / 10

------------------------------------------------------------

Common Mistakes:

❌ Forgetting carry at end
❌ Not handling unequal length lists
❌ Missing node creation

------------------------------------------------------------

Better Optimization (for interview):

Use dummy node to simplify code

------------------------------------------------------------

Interview Line:

"Traverse both lists, add digits with carry,
build result list node by node."

------------------------------------------------------------

Mental Shortcut:

Add → Carry → Build

------------------------------------------------------------
*/