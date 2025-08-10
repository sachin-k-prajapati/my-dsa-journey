/*
 * Problem: [LeetCode-236] Lowest Common Ancestor of a Binary Tree
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * Definition:
 * Given the root of a binary tree and two nodes p and q, find the lowest common ancestor (LCA).
 * The LCA is the deepest node that has both p and q as descendants (a node can be a descendant of itself).
 *
 * Example:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 *
 * Constraints:
 * - Number of nodes in [2, 1e5]
 * - Node values are unique
 * - p != q and both exist in the tree
 *
 * ----------------------------------------------------------------------------
 * Approach 1 (Path Storage Method):
 *  - Store the path from root to p and root to q in two vectors.
 *  - Compare both paths until nodes differ; the last common node is the LCA.
 *
 *  Justification:
 *  - Straightforward method that uses simple DFS and stores the path.
 *  - Easy to understand and debug.
 *
 *  Time Complexity: O(N) — DFS for both p and q, where N is number of nodes.
 *  Space Complexity: O(N) — storing paths for both nodes.
 *
 *  Edge Cases:
 *  - p is ancestor of q or vice versa.
 *  - p and q are on completely different subtrees.
 *
 * ----------------------------------------------------------------------------
 * Approach 2 (Recursive DFS without extra storage):
 *  - Traverse recursively:
 *      - If current node is NULL, return NULL.
 *      - If current node is p or q, return current node.
 *      - Recursively search left and right subtrees.
 *  - If both left and right return non-null, current node is LCA.
 *  - If only one side returns non-null, propagate that upwards.
 *
 *  Justification:
 *  - More space efficient, no need to store paths.
 *  - Elegant recursion leverages post-order traversal.
 *
 *  Time Complexity: O(N)
 *  Space Complexity: O(H) — recursion stack, where H is tree height.
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Path method explicitly tracks where both nodes are located and their
 *   divergence point.
 * - Recursive method works by backtracking from leaves upwards, detecting
 *   the exact point where both targets are found in different branches.
 * - Recursive approach is generally preferred for cleaner implementation,
 *   but path storage is useful when we also need explicit paths for other use cases.
 */

// -----------------------------
// First Solution: Path Storage
// -----------------------------

// Include necessary headers
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_Path {
public:
    // Helper function to find the path from root to a given node.
    // Stores the path in 'res' vector.
    bool findNode(TreeNode* root, TreeNode* node, vector<TreeNode*>& res) {
        if (!root) return false; // Base case: reached null
        
        res.push_back(root); // Add current node to path
        
        if (root == node) return true; // Found target
        
        // Search left and right subtrees
        if (root->left && findNode(root->left, node, res)) return true;
        if (root->right && findNode(root->right, node, res)) return true;
        
        // Backtrack if not found
        res.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecp; // path from root to p
        vector<TreeNode*> vecq; // path from root to q
        
        findNode(root, p, vecp);
        findNode(root, q, vecq);

        int i = 0;
        // Traverse until paths differ
        while (i < vecp.size() && i < vecq.size()) {
            if (vecp[i] != vecq[i]) return vecp[i - 1]; 
            i++;
        }
        return vecp[i - 1];
    }
};

// -----------------------------
// Second Solution: Recursive DFS
// -----------------------------

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_Recursive {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if current node is null or matches p/q
        if (!root || root == p || root == q) return root;

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right returned non-null, current node is LCA
        if (left && right) return root;

        // Otherwise, propagate non-null result upwards
        return left ? left : right;
    }
};
