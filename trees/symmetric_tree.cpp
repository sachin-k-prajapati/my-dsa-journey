/*
 * Problem: LeetCode-101 Symmetric Tree
 * Source: LeetCode
 * LINK: https://leetcode.com/problems/symmetric-tree/description/
 *
 * Definition:
 * Given the root of a binary tree, check if it is symmetric 
 * around its center (mirror image of itself).
 *
 * Example:
 * Input:  [1,2,2,3,4,4,3]  => Output: true
 * Input:  [1,2,2,null,3,null,3] => Output: false
 *
 * -------------------------------------------------------------------
 * APPROACH:
 * We can solve this in **two ways**:
 * 
 * 1. **Recursive Approach**:
 *    - Compare left subtree of left node with right subtree of right node.
 *    - Compare right subtree of left node with left subtree of right node.
 *    - Recursively check if these pairs are equal at all levels.
 *    - Base cases:
 *        a) Both nodes are NULL => symmetric at this point.
 *        b) One node is NULL, other not => not symmetric.
 *        c) Values differ => not symmetric.
 * 
 * 2. **Iterative Approach** (Using Queue):
 *    - Store node pairs to be compared in a queue.
 *    - At each step, check:
 *        a) If values match.
 *        b) If left child of left node matches right child of right node.
 *        c) If right child of left node matches left child of right node.
 *    - Push these matched pairs into queue for further checking.
 *
 * -------------------------------------------------------------------
 * KEY POINTS:
 * - Time Complexity: O(N) where N is number of nodes (we check each node once).
 * - Space Complexity: O(H) for recursion (stack) or O(N) for BFS queue.
 * - Works for:
 *     a) Empty tree (trivially symmetric).
 *     b) Single node tree (trivially symmetric).
 * - Edge Cases:
 *     a) Root has only one child → NOT symmetric.
 *     b) Duplicate values but different structure → NOT symmetric.
 *
 * -------------------------------------------------------------------
 * DEEP INTUITION:
 * Symmetry in trees is like holding a mirror at the root:
 * - The "outer" children (left of left subtree, right of right subtree) must match.
 * - The "inner" children (right of left subtree, left of right subtree) must match.
 * - This relationship holds recursively for every subtree.
 *
 * Recursion feels very natural here because the definition of symmetry 
 * is inherently recursive. However, iterative BFS can sometimes be 
 * preferred to avoid stack overflow for very deep trees.
 */

#include <bits/stdc++.h>
using namespace std;

/* -------------------------------------------------------------------
   Recursive Solution
   ------------------------------------------------------------------- */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionRecursive {
public:
    // Helper function to check if two subtrees are mirror images
    bool check(TreeNode* rootl, TreeNode* rootr) {
        // Case 1: Both null → symmetric at this point
        if (!rootl && !rootr) return true;

        // Case 2: One null, one not → asymmetric
        if (!rootl || !rootr) return false;

        // Case 3: Both exist → values must match & subtrees must mirror each other
        return (rootl->val == rootr->val) && 
               check(rootl->left, rootr->right) && 
               check(rootl->right, rootr->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // Empty tree is symmetric
        return check(root->left, root->right);
    }
};

/* -------------------------------------------------------------------
   Iterative Solution
   ------------------------------------------------------------------- */
class SolutionIterative {
public:
    bool isSymmetric(TreeNode* root) {
        // Queue stores pairs of nodes to compare
        queue<pair<TreeNode*, TreeNode*>> Queue;

        // Initial check for children of root
        if (root->left && root->right) {
            Queue.push({root->left, root->right});
        } else if (root->left || root->right) {
            return false; // Only one child → asymmetric
        }

        while (!Queue.empty()) {
            TreeNode* nodeLeft = Queue.front().first;
            TreeNode* nodeRight = Queue.front().second;
            Queue.pop();

            // Values must match
            if (nodeLeft->val != nodeRight->val) return false;

            // Compare outer pair: left child of left node & right child of right node
            if (nodeLeft->left && nodeRight->right) {
                Queue.push({nodeLeft->left, nodeRight->right});
            } else if (nodeLeft->left || nodeRight->right) {
                return false; // Only one exists → asymmetric
            }

            // Compare inner pair: right child of left node & left child of right node
            if (nodeLeft->right && nodeRight->left) {
                Queue.push({nodeLeft->right, nodeRight->left});
            } else if (nodeLeft->right || nodeRight->left) {
                return false;
            }
        }

        return true; // All checks passed
    }
};
