/*
Problem: Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/

Definition:
Given the head of a singly linked list,
reverse the linked list and return the new head.

Example:

Input:
1 → 2 → 3 → 4 → 5

Output:
5 → 4 → 3 → 2 → 1

------------------------------------------------------------

Approach 1: Iterative (Three Pointer Method)

We use 3 pointers:

prev     → previous node
curr     → current node
nextNode → store next node safely

Why?

Because when we reverse:

curr->next = prev

we lose access to the remaining list.

So first save:
nextNode = curr->next

Then reverse safely.

Steps:

1. Save next node
2. Reverse current link
3. Move prev forward
4. Move curr forward

At the end:
prev becomes new head

------------------------------------------------------------

Approach 2: Recursive

Idea:

Go till the last node first.

Then while returning back:

reverse the links.

Example:

1 → 2 → 3

Recursive calls reach:

3

Then while returning:

2->next->next = 2
1->next->next = 1

Final:
3 → 2 → 1

Very elegant recursive approach.

------------------------------------------------------------

Key Points:

Iterative:

Time Complexity: O(N)
Space Complexity: O(1)

Recursive:

Time Complexity: O(N)
Space Complexity: O(N)
(recursion stack)

------------------------------------------------------------

Deep Intuition:

This is one of the most important
Linked List interview problems.

Core idea:

"Reverse direction of next pointers"

Original:

1 → 2 → 3

After reverse:

1 ← 2 ← 3

Need to carefully preserve the next node
before changing pointers.

That is the entire trick.

*/

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


// ============================================================
// Solution 1: Iterative Approach
// ============================================================

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // prev will point to previous node
        ListNode* prev = nullptr;

        // curr starts from head
        ListNode* curr = head;

        while (curr) {

            // Save next node before breaking link
            ListNode* nextNode = curr->next;

            // Reverse current pointer
            curr->next = prev;

            // Move prev one step ahead
            prev = curr;

            // Move curr one step ahead
            curr = nextNode;
        }

        // prev becomes new head
        return prev;
    }
};



/*
------------------------------------------------------------
Solution 2: Recursive Approach
------------------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Base case:
        // empty list or single node list
        if (!head || !head->next) {
            return head;
        }

        // Reverse rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse current connection
        head->next->next = head;

        // Break old forward link
        head->next = nullptr;

        // Return new head from deepest call
        return newHead;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List Pointer Manipulation

Most Important Trick:

Before changing:
save next node first

Because:
once pointer changes,
remaining list may be lost

Iterative Formula:

next = curr->next
curr->next = prev
prev = curr
curr = next

Recursive Formula:

head->next->next = head
head->next = NULL

Common Mistakes:

- forgetting nextNode
- creating cycle by missing:
  head->next = NULL
- returning wrong head

Interview Line:

"Reverse pointers one by one using
three pointers or recursion."

Mental Shortcut:

Save → Reverse → Move

------------------------------------------------------------
*/