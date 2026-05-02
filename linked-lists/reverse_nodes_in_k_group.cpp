/*
Problem: Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

Definition:
Given a linked list, reverse nodes in groups of size k.
If remaining nodes are less than k → leave them as it is.

IMPORTANT:
❌ Cannot change values
✅ Only pointer manipulation allowed

------------------------------------------------------------

Approach:

Group-wise Reversal (Iterative)

Steps:
1. Count total nodes
2. Determine how many full groups (count / k)
3. For each group:
    - Reverse k nodes using standard LL reversal
    - Connect:
        previous group's tail → new head of reversed group
        reversed group's tail → next segment

------------------------------------------------------------

Why this works:

Instead of reversing entire list,
we reverse fixed chunks (size k)

→ Local reversal + proper linking = final result

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Edge Cases:

- k = 1 → no change
- n < k → no reversal
- Exact multiple of k → full reversal
- Last group < k → untouched

------------------------------------------------------------

Deep Intuition:

Think like blocks:

[1,2,3,4,5,6]
k = 3

→ Reverse blocks:
[1,2,3] → [3,2,1]
[4,5,6] → [6,5,4]

------------------------------------------------------------

Critical Understanding:

You must maintain:
1. Start of current group (first)
2. Previous group's tail (temp2)
3. Next node before breaking links

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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Edge case: single node or k = 1
        if (!head->next || k == 1) return head;

        
        ListNode* temp = head;      // traversal pointer
        ListNode* temp2 = head;     // previous group's tail (initially head)

        int count = 1;

        // Step 1: Count total nodes
        while (temp && temp->next) {
            count++;
            temp = temp->next->next;
            if (temp) count++;
        }

        temp = head;

        // Number of full groups
        int l = count / k;

        // Step 2: Process each group
        while (temp && l--) {

            int n = k;                 // number of nodes to reverse is equals to k

            ListNode* pre = nullptr;     // previous pointer for reversal
            ListNode* first = temp;   // first node of current group

            // Reverse k nodes
            while (n--) {
                ListNode* nextnode = temp->next;
                temp->next = pre;
                pre = temp;
                temp = nextnode;
            }

            // Connect tail of reversed group to next segment
            first->next = temp;

            // Update head for first group
            if (temp2 == head) {
                head = pre;
            }
            else {
                // Connect previous group's tail to new head
                temp2->next = pre;
                // Move temp2 to current group's tail for next connection
                temp2 = first;
            }
        }

        return head;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List Block Reversal

------------------------------------------------------------

Core Idea:

Reverse in chunks of size k

------------------------------------------------------------

Key Variables:

temp → current pointer
pre → reversed list pointer
first → original start of group (becomes tail)
temp2 → previous group's tail

------------------------------------------------------------

Critical Linking:

After reversing:
first->next = next group

Previous group:
temp2->next = new head (pre)

------------------------------------------------------------

Common Mistakes:

❌ Forgetting to connect groups
❌ Losing next pointer during reversal
❌ Reversing last incomplete group
❌ Not updating head for first group

------------------------------------------------------------

Interview Line:

"Reverse linked list in fixed-size blocks using pointer manipulation."

------------------------------------------------------------

Mental Model:

[1,2,3,4,5]
k = 2

→ [2,1] [4,3] [5]

------------------------------------------------------------
*/