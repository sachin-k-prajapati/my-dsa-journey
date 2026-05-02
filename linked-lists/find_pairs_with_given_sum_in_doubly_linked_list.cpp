/*
Problem: Pair Sum in Doubly Linked List
Link: https://www.geeksforgeeks.org/problems/pair-sum-in-doubly-linked-list/1

Definition:
Given a SORTED doubly linked list with distinct positive values,
find all pairs of nodes whose sum equals the given target.

Return all such pairs.

------------------------------------------------------------

Approach:

Two Pointer Technique (Same as sorted array)

- Use two pointers:
    head → smallest element
    tail → largest element

Steps:
1. Move tail to last node
2. While head != tail:
    - Compute sum = head->data + tail->data
    - If sum == target:
        → store pair
        → move tail backward
    - If sum > target:
        → decrease sum → move tail backward
    - If sum < target:
        → increase sum → move head forward

------------------------------------------------------------

Why this works:

Because DLL is SORTED:
→ Increasing head increases sum
→ Decreasing tail decreases sum

Same intuition as:
"Two Sum in Sorted Array"

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1) (excluding result storage)

------------------------------------------------------------

Edge Cases:

- No pair exists → return empty vector
- Single node → no pair
- Two nodes → one possible pair
- head == tail → stop

------------------------------------------------------------

Deep Intuition:

Think like:
Smallest + Largest

If too big → reduce largest
If too small → increase smallest

DLL advantage:
→ Can move both directions efficiently

------------------------------------------------------------
*/
#include<vector>
#include<utility>
using namespace std;

// Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int, int>> res;

        // Step 1: Move to tail (last node)
        Node* tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        // Step 2: Two pointer traversal
        while (head != tail) {

            int sum = head->data + tail->data;

            // Case 1: Pair found
            if (sum == target) {
                res.emplace_back(head->data, tail->data);

                // Move tail backward to avoid duplicates
                tail = tail->prev;

                // Important: check crossing condition
                if (head == tail) break;
            }

            // Case 2: Sum too large → reduce it
            if (sum > target) {
                tail = tail->prev;
            }
            // Case 3: Sum too small → increase it
            else {
                head = head->next;
            }
        }

        return res;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Two Pointer on Sorted Data Structure

------------------------------------------------------------

Core Idea:

Use two ends:
→ left (small)
→ right (large)

------------------------------------------------------------

Movement Rule:

sum < target → move left forward
sum > target → move right backward

------------------------------------------------------------

Why DLL?

Because:
→ We can move both directions easily

------------------------------------------------------------

Common Mistakes:

❌ Forgetting list is sorted (required!)
❌ Infinite loop (not handling head == tail)
❌ Not checking crossing condition
❌ Moving wrong pointer

------------------------------------------------------------

Interview Line:

"Use two-pointer approach leveraging sorted property of DLL."

------------------------------------------------------------

Mental Model:

Like array:
[1,2,4,5,6,8,9]

head → 1
tail → 9

Move inward based on sum

------------------------------------------------------------
*/