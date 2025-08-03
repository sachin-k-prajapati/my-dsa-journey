// LeetCode: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
// Problem: Insert the GCD of adjacent node values between every pair of nodes in a linked list

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
    // Recursive Euclidean Algorithm to find GCD
    int gcdCalc(int a, int b) {
        if (b == 0)
            return a;
        return gcdCalc(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) return head;

        ListNode* temp = head;

        while (temp->next) {
            ListNode* prev = temp;
            temp = temp->next;

            int gcd = gcdCalc(prev->val, temp->val);

            // Create and insert new node with GCD
            ListNode* insertNode = new ListNode(gcd);
            insertNode->next = temp;
            prev->next = insertNode;
        }

        return head;
    }
};

/*
---------------------------------------
🧠 APPROACH:
---------------------------------------
1. Traverse the linked list using two pointers (`prev`, `temp`)
2. Calculate GCD of adjacent nodes' values using recursive Euclidean algorithm
3. Create a new node with the GCD value and insert it between the two nodes
4. Move to the next pair and repeat

---------------------------------------
⏱️ TIME & SPACE COMPLEXITY:
---------------------------------------
- Time: O(N * log(min(a,b))) for N nodes
- Space: O(1) (excluding recursion stack for GCD)

---------------------------------------
📌 NOTES FOR FUTURE:
---------------------------------------
- Handles edge case: single-node list
- Recursive GCD is readable and fine here since inputs are small
- If asked in interviews, iterative GCD avoids stack overhead
- Modifies the linked list **in-place**
- Be careful when changing pointers; memory leaks or cycles can happen if `next` links are mishandled

*/
