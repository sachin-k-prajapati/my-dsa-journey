/*
Problem: Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

Definition:
Given two singly linked lists, return the node where they intersect.
If no intersection exists, return NULL.

Important:
Intersection means SAME NODE (same memory reference), not same value.

------------------------------------------------------------

Approach:

Two Pointer Technique (Pointer Switching)

- Use two pointers:
    ptrA → headA
    ptrB → headB

- Traverse both lists:
    If ptrA reaches end → move it to headB
    If ptrB reaches end → move it to headA

- Eventually:
    They will meet at intersection OR both become NULL

------------------------------------------------------------

Why this works:

Let:
Length A = m
Length B = n

After switching:
ptrA travels = m + n
ptrB travels = n + m

=> Equal distance → synchronized meeting

------------------------------------------------------------

Key Points:

Time Complexity: O(m + n)
Space Complexity: O(1)

------------------------------------------------------------

Edge Cases:

- No intersection → both become NULL
- One list empty → no intersection
- Intersection at head → immediate return
- Different lengths handled automatically

------------------------------------------------------------

Deep Intuition:

Instead of aligning lengths manually,
we let pointers "self-adjust" by switching lists.

This removes need for:
❌ length calculation
❌ extra space

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Two pointers starting from both heads
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Note*: We use OR condition because we want to continue until both are NULL
        // If we used AND, we would stop when one becomes NULL, which is incorrect
        // Note*: if lenght of skipA is m, and skipB is n, and intersection length is k, then:
        // ptrA travels: m + k + n
        // ptrB travels: n + k + m
        // ptrA == ptrB (the math works out because both travel m + n + k steps to reach intersection or end)
        // So they will meet at intersection after m + n steps, or both become NULL if no intersection

        // Traverse until both meet
        while (ptrA || ptrB) {

            // If ptrA reaches end, redirect to headB
            if (!ptrA) ptrA = headB;

            // If ptrB reaches end, redirect to headA
            if (!ptrB) ptrB = headA;

            // If both pointers meet → intersection found
            if (ptrA == ptrB) return ptrA;

            // Move both pointers ahead
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        // No intersection
        return nullptr;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Two Pointer Synchronization

------------------------------------------------------------

Core Idea:

Make both pointers travel equal distance

------------------------------------------------------------

Key Trick:

Switch heads when reaching NULL

------------------------------------------------------------

Why powerful?

No need to:
❌ Find lengths
❌ Adjust pointers manually

------------------------------------------------------------

Common Mistakes:

❌ Comparing values instead of nodes
❌ Forgetting pointer switching
❌ Using extra memory (hashing)

------------------------------------------------------------

Interview Line:

"Use two pointers and switch heads to equalize path length."

------------------------------------------------------------

Mental Model:

A → B path
B → A path

Both pointers traverse same total length

------------------------------------------------------------
*/