/*
Problem: Remove Duplicates from Sorted List II
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Definition:
Given a sorted linked list, delete ALL nodes that have duplicate values.
Only keep nodes that appear exactly once.

Example:
[1,2,3,3,4,4,5] → [1,2,5]

------------------------------------------------------------

Approach:

Pointer Tracking + Duplicate Skipping

- Use two pointers:
    temp → current node
    preTrack → last confirmed unique node

- Traverse the list:
    Case 1: No duplicate → move forward normally
    Case 2: Duplicate found:
        → Remove ALL nodes with that value
        → Fix links using preTrack

------------------------------------------------------------

Why this works:

Because list is SORTED:
→ Duplicates are always adjacent

So:
→ Once duplicate is detected, we can remove entire block in one go

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Edge Cases:

- Head itself is duplicate → update head
- Entire list duplicates → return NULL
- Single node → return as is
- Multiple duplicate blocks

------------------------------------------------------------

Deep Intuition:

Difference from "Remove Duplicates I":

❌ That keeps ONE copy
✅ This removes ALL duplicates completely

So:
If a value repeats → remove ALL occurrences

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
    ListNode* deleteDuplicates(ListNode* head) {

        // Edge case: empty list
        if (head == nullptr) return head;

        ListNode* temp = head;        // traversal pointer
        ListNode* preTrack = nullptr;   // last confirmed non-duplicate node

        while (temp) {

            // If last node → nothing to compare
            if (temp->next == nullptr) {
                return head;
            } 
            else {

                // Case: duplicate found
                if (temp->next->val == temp->val) {

                    ListNode* duplicate = temp;
                    int dup = duplicate->val;

                    // Remove all nodes with same value
                    while (duplicate->next && duplicate->next->val == dup) {
                        ListNode* deleteNode = duplicate->next;
                        duplicate->next = deleteNode->next;
                        delete deleteNode;
                    }

                    // Move temp back to previous valid node
                    temp = preTrack;

                    // If previous exists → link it to next valid node
                    if (temp) {
                        temp->next = duplicate->next;
                    } 
                    else {
                        // Duplicate was at head → update head
                        temp = duplicate->next;
                        head = temp;
                    }

                    // Delete original duplicate node
                    delete duplicate;
                } 
                else {
                    // No duplicate → move forward
                    preTrack = temp;
                    temp = temp->next;
                }
            }
        }

        // If temp becomes NULL → list exhausted
        if (!temp) {
            head = temp;
        }

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List Duplicate Removal (Advanced)

------------------------------------------------------------

Core Idea:

If duplicate found → REMOVE ENTIRE GROUP

------------------------------------------------------------

Important Variables:

temp → current node
preTrack → last safe (non-duplicate) node

------------------------------------------------------------

Critical Logic:

Detect duplicate:
temp->val == temp->next->val

Then:
Remove ALL occurrences

------------------------------------------------------------

Special Case:

If duplicate starts at head:
→ Update head

------------------------------------------------------------

Common Mistakes:

❌ Only removing one duplicate (wrong problem)
❌ Forgetting to update head
❌ Losing track of previous pointer
❌ Memory leaks (not deleting nodes)

------------------------------------------------------------

Interview Line:

"Since list is sorted, duplicates are contiguous, so we remove them in one pass."

------------------------------------------------------------

Mental Model:

[1,2,3,3,4,4,5]

At 3:
→ remove ALL 3s
At 4:
→ remove ALL 4s

Result:
[1,2,5]

------------------------------------------------------------
*/