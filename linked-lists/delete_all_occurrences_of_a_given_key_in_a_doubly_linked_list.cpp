/*
Problem: Delete all occurrences of a given key in a Doubly Linked List
Link: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

Definition:
Given the head of a Doubly Linked List (DLL) and a key X, delete all nodes whose value equals X.
Return the updated list.

------------------------------------------------------------

Approach:

Single traversal with pointer manipulation

- Traverse the DLL using a pointer `temp`
- For each node:
    → If value == key:
        Case 1: Node is head
            - Move head forward
            - Update new head's prev = NULL
        Case 2: Node is middle/tail
            - Link prev node to next node
            - Link next node back to prev node
        - Delete the current node
    → Else move forward

------------------------------------------------------------

Why this approach:

- DLL allows bidirectional updates
- We can delete a node in O(1) without traversal back
- Only one pass required → optimal

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1)

------------------------------------------------------------

Edge Cases:

- Multiple consecutive nodes with key
- Head node(s) contain key
- Entire list consists of key → result becomes NULL
- Single node list
- Last node deletion

------------------------------------------------------------

Deep Intuition:

DLL gives power:
→ Each node knows its previous AND next

So deleting a node is just:
prev->next = next
next->prev = prev

But head is special:
→ No prev pointer → must update head separately

Important:
Always store next before deleting or update pointer carefully

------------------------------------------------------------
*/

using namespace std;

/* a Node of the doubly linked list
*/
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {

        // Start traversal from head
        Node* temp = *head_ref;

        while (temp) {

            // Case 1: Node to delete is head
            if (temp->data == x && temp == *head_ref) {

                // Move head forward
                *head_ref = (*head_ref)->next;

                // Fix new head's prev pointer
                if (*head_ref) (*head_ref)->prev = nullptr;

                // Store node to delete
                Node* toDelete = temp;

                // Move temp to new head
                temp = *head_ref;

                // Delete old head
                delete toDelete;
            }

            // Case 2: Node to delete is middle or tail
            else if (temp->data == x) {

                // Bypass current node
                temp->prev->next = temp->next;

                // Fix backward link if next exists
                if (temp->next) temp->next->prev = temp->prev;

                // Store node to delete
                Node* toDelete = temp;

                // Move temp ahead BEFORE deleting
                temp = temp->next;

                // Delete node
                delete toDelete;
            }

            // Case 3: Normal node → move ahead
            else {
                temp = temp->next;
            }
        }
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Linked List Node Deletion (DLL)

------------------------------------------------------------

Core Idea:

Handle deletion in 3 cases:
1. Head node
2. Middle node
3. Tail node

------------------------------------------------------------

Important Trick:

Always move pointer BEFORE deleting node
→ Avoid losing reference

------------------------------------------------------------

Why DLL is easier than Singly LL?

Because:
→ You have prev pointer → direct back-link updates

------------------------------------------------------------

Common Mistakes:

❌ Forgetting to update head
❌ Not handling prev pointer
❌ Accessing deleted memory
❌ Not checking temp->next before accessing prev

------------------------------------------------------------

Interview Line:

"Use pointer manipulation with careful handling of head node."

------------------------------------------------------------

Mental Model:

Cut the node out:
prev <-> [node] <-> next

becomes:

prev <------> next

------------------------------------------------------------
*/