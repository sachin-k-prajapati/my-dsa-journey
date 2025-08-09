/*
===========================================
Leetcode 100. Same Tree
LINK: https://leetcode.com/problems/same-tree/
===========================================

📌 Problem (short & clear):
Given roots of two binary trees p and q, determine if they are "exactly the same".
Two binary trees are the same if:
    1. They have the same structure (same arrangement of left/right children)
    2. Corresponding nodes have equal values.

-------------------------------------------
💡 Examples:
-------------------------------------------
Example 1:
p = [1,2,3], q = [1,2,3]  → true  (Identical)

Example 2:
p = [1,2], q = [1,null,2] → false (Different structure)

Example 3:
p = [1,2,1], q = [1,1,2]  → false (Same structure but different values)

-------------------------------------------
📏 Constraints:
- Node count: [0, 100]
- Node values: [-10^4, 10^4]

-------------------------------------------
🔍 Intuition:
-------------------------------------------
This is basically a **tree comparison** problem.
We need to compare both trees node-by-node:
    - If both nodes are null → they match here.
    - If one node is null but not the other → different.
    - If values differ → different.
    - Otherwise → recursively check left and right subtrees.

This is naturally recursive, but can also be implemented iteratively (BFS/DFS).

-------------------------------------------
🛠 Approaches Covered:
-------------------------------------------
1️⃣ Recursive DFS (with extra bool flag) → My first approach
2️⃣ Cleaner Recursive DFS → Direct & readable

-------------------------------------------
📚 Time & Space Complexity:
-------------------------------------------
Time Complexity: O(N)  // We visit each node exactly once
Space Complexity:
    - O(H) for recursion stack in worst case (H = tree height)
    - Worst case O(N) for skewed trees

-------------------------------------------
*/

// =========================================
// 📌 First Approach (Recursive DFS with extra flag)
// =========================================

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool checkForSame(TreeNode* p, TreeNode* q, bool check) {
        // If already false somewhere, no need to check further
        if (!check) return false;

        // Both null → match here
        if (!p && !q) return true;

        // Both non-null → compare values & recurse
        if (p && q) {
            if (p->val != q->val) return false;
            check = checkForSame(p->left, q->left, check);
            check = checkForSame(p->right, q->right, check);
        } 
        // One null & one non-null → not same
        else {
            return false;
        }
        return check;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check = true;
        return checkForSame(p, q, check);
    }
};


// =========================================
// 📌 Second Approach (Cleaner Recursive DFS)
// =========================================
// This is the standard and most readable way to solve this problem.

class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: Both null → match
        if (!p && !q) return true;

        // Case 2: One null → not same
        if (!p || !q) return false;

        // Case 3: Values differ → not same
        if (p->val != q->val) return false;

        // Case 4: Values same → check left and right recursively
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
-------------------------------------------
📝 Notes for Revision:
-------------------------------------------
✔ The problem is a direct application of DFS tree traversal.
✔ Null checks are extremely important; the order matters.
✔ Cleaner approach (Solution2) is easier to read & debug.
✔ Time complexity is always O(N), where N = number of nodes.
✔ Recursive solution is the most natural, but iterative BFS with queues is also possible.
✔ Avoid unnecessary state variables unless needed for other constraints.

-------------------------------------------
End of Notes
-------------------------------------------
*/
