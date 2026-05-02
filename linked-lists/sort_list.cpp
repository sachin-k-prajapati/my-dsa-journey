/*
Problem: Sort List
Link: https://leetcode.com/problems/sort-list/

Definition:
Given the head of a linked list,
sort the list in ascending order.

------------------------------------------------------------

Approach:

Use Merge Sort on Linked List

Why?

- Linked list does NOT support random access
- Quick sort is not ideal here
- Merge sort works efficiently in O(N log N)

------------------------------------------------------------

Steps:

1. Find middle of list
2. Split into two halves
3. Recursively sort both halves
4. Merge sorted halves

------------------------------------------------------------

Key Points:

Time Complexity: O(N log N)
Space Complexity: O(log N) (recursion stack)

------------------------------------------------------------

Deep Intuition:

Array → merge sort uses indices  
Linked List → we use pointers

Instead of mid index,
we find middle using slow-fast pointer

------------------------------------------------------------

Example:

4 → 2 → 1 → 3

Split:

4 → 2     1 → 3

Further split:

4   2     1   3

Merge:

2 → 4     1 → 3

Final merge:

1 → 2 → 3 → 4

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

    // Merge two sorted linked lists
    ListNode* mergeSortedLists(ListNode* left, ListNode* right) {

        // Dummy node to simplify logic
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge both lists
        while (left && right) {

            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = left ? left : right;

        return dummy.next;
    }

    // Find middle of linked list
    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {

        // Base case
        if (!head || !head->next) return head;

        // Step 1: Find middle
        ListNode* mid = findMid(head);

        // Split list into two halves
        ListNode* secondHead = mid->next;
        mid->next = nullptr;

        // Step 2: Recursively sort both halves
        ListNode* leftPart = sortList(head);
        ListNode* rightPart = sortList(secondHead);

        // Step 3: Merge sorted halves
        return mergeSortedLists(leftPart, rightPart);
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Merge Sort on Linked List

------------------------------------------------------------

Core Steps:

Split → Sort → Merge

------------------------------------------------------------

Why merge sort?

Because linked list:
❌ No random access
❌ Cannot use quick sort efficiently

------------------------------------------------------------

Key Trick:

Use slow-fast pointer to find middle

------------------------------------------------------------

Important Detail:

mid->next = NULL

This splits list properly

------------------------------------------------------------

Common Mistakes:

❌ Not breaking list into two halves
❌ Wrong mid calculation
❌ Forgetting base case
❌ Incorrect merge logic

------------------------------------------------------------

Interview Line:

"Use merge sort because it guarantees
O(N log N) for linked lists."

------------------------------------------------------------

Mental Shortcut:

Divide → Conquer → Merge

------------------------------------------------------------
*/