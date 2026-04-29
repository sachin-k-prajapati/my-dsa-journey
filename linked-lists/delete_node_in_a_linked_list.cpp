/*
========================================================
237. Delete Node in a Linked List
========================================================

Problem:
You are given a node in a singly linked list.

IMPORTANT:
You are NOT given the head of the linked list.

Your task is to delete that given node such that:

1. The value of that node should no longer exist
2. Total number of nodes decreases by 1
3. Order of previous nodes remains same
4. Order of next nodes remains same

Also:
-> The given node is guaranteed to NOT be the last node

--------------------------------------------------------
Example:

Input:
4 -> 5 -> 1 -> 9
Given node = 5

Output:
4 -> 1 -> 9

--------------------------------------------------------
Main Observation

Normally, to delete a node in a linked list:

prev->next = node->next

But here:

We do NOT have access to previous node
We do NOT have access to head

So normal deletion is impossible.

--------------------------------------------------------
Smart Trick

Since the given node is NOT the last node:

We can copy the value of the next node
into the current node.

Then delete the next node instead.

Example:

4 -> 5 -> 1 -> 9

Given node = 5

Step 1:
Copy next node value

4 -> 1 -> 1 -> 9

Step 2:
Remove the next node

4 -> 1 -> 9

Now it looks like node 5 was deleted.

--------------------------------------------------------
Approach

1. Copy next node's value into current node

   node->val = node->next->val;

2. Store next node temporarily

   ListNode* toDelete = node->next;

3. Skip next node

   node->next = node->next->next;

4. Free memory of removed node

   delete toDelete;

--------------------------------------------------------
Why This Works

Because values are unique,
replacing current node with next node’s value
makes the original value disappear.

Then removing next node reduces list size by 1.

This perfectly simulates deletion.

--------------------------------------------------------
Time Complexity

O(1)

Only constant operations performed.

--------------------------------------------------------
Space Complexity

O(1)

No extra space used.

--------------------------------------------------------
*/

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
    void deleteNode(ListNode* node) {

        // Copy value of next node into current node
        node->val = node->next->val;

        // Store next node so we can delete it later
        ListNode* toDelete = node->next;

        // Skip the next node
        node->next = node->next->next;

        // Free memory of removed node
        delete toDelete;
    }
};