/*
 * Problem: Largest BST in a Binary Tree
 * Link: https://www.geeksforgeeks.org/problems/largest-bst/1
 *
 * Definition:
 * - Given a binary tree (not necessarily a BST), find the size (number of nodes)
 *   of the largest subtree that is a valid Binary Search Tree.
 * - Subtree must follow BST properties:
 *     - Left subtree < root < Right subtree
 *     - No duplicate values
 *
 * Example:
 * Input: root = [5, 2, 4, 1, 3]
 * Output: 3
 * Explanation: The subtree [2,1,3] is a valid BST of size 3.
 *
 * Constraints:
 * - 1 ≤ number of nodes ≤ 1e5
 * - 1 ≤ node->data ≤ 1e5
 *
 * ----------------------------------------------------------------------------
 * Approach 1 (Brute Force DFS):
 * - For every node:
 *   - Check if its subtree is a BST (using min/max ranges).
 *   - If yes → calculate size of this subtree.
 *   - Else → check left and right recursively.
 * - Maintain the maximum size found.
 *
 * Complexity:
 * - Time: O(N^2) in worst case (checking each node + subtree validation).
 * - Space: O(H) recursion stack.
 * - Works but can be too slow for large inputs.
 *
 * ----------------------------------------------------------------------------
 * Approach 2 (Optimized - Bottom Up with Info Struct):
 * - Post-order traversal (left, right, root).
 * - Each node returns a "BSTInfo" struct:
 *   - min value in subtree
 *   - max value in subtree
 *   - size of largest BST in subtree
 *   - whether subtree is BST
 * - If left and right are BST and satisfy BST property → merge into bigger BST.
 * - Else, propagate the larger of left/right BST sizes upward.
 *
 * Complexity:
 * - Time: O(N) → each node processed once.
 * - Space: O(H) recursion stack.
 * - Efficient and handles large trees.
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Brute force = “Check every possible subtree as root” → simple but slow.
 * - Optimized = “Collect and merge info bottom-up” → avoids repeated work.
 *   - At each node, we just ask children: 
 *     "Are you BSTs? What’s your min, max, size?" 
 *   - Then decide if the current subtree is also BST.
 * - This bottom-up design is very powerful in tree DP problems.
 */


/* Tree node structure used in the program */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



// -------------------------
// Solution 1: Brute Force
// -------------------------
class Solution1 {
public:
    int largestBST = 0; // track largest BST size

    // Helper to check if subtree is a BST within (low, high) range
    bool isBST(Node* root, int low, int high) {
        if (!root) return true;
        if (root->data <= low || root->data >= high) return false;

        return isBST(root->left, low, root->data) &&
               isBST(root->right, root->data, high);
    }

    // Count nodes in subtree
    int numberOfNodes(Node* root) {
        if (!root) return 0;
        return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
    }

    // Recursive traversal to check all subtrees
    void helper(Node* root) {
        if (!root) return;

        // If subtree is BST → update largestBST
        if (isBST(root, INT_MIN, INT_MAX)) {
            largestBST = max(largestBST, numberOfNodes(root));
        }

        // Recurse left & right
        helper(root->left);
        helper(root->right);
    }

    int largestBst(Node* root) {
        helper(root);
        return largestBST;
    }
};


// -------------------------
// Solution 2: Optimized O(N)
// -------------------------

// Struct to hold info for each subtree
class BSTInfo {
public:
    int mn;       // minimum value in subtree
    int mx;       // maximum value in subtree
    int mxsize;   // size of largest BST in subtree
    bool isBST;   // is this subtree a BST?

    BSTInfo(int mn, int mx, int mxsize, bool isBST) {
        this->mn = mn;
        this->mx = mx;
        this->mxsize = mxsize;
        this->isBST = isBST;
    }
};

class Solution2 {
public:
    BSTInfo findBST(Node* root) {
        if (!root) {
            // Base case: empty tree is BST
            return BSTInfo(INT_MAX, INT_MIN, 0, true);
        }

        // Get info from left & right subtrees
        BSTInfo left = findBST(root->left);
        BSTInfo right = findBST(root->right);

        // If both sides are BST and root is valid → whole tree is BST
        if (left.isBST && right.isBST &&
            left.mx < root->data && right.mn > root->data) {
            return BSTInfo(
                min(left.mn, root->data),
                max(right.mx, root->data),
                1 + left.mxsize + right.mxsize,
                true
            );
        }

        // Otherwise, not a BST → propagate max size found so far
        return BSTInfo(
            INT_MIN, INT_MAX,
            max(left.mxsize, right.mxsize),
            false
        );
    }

    int largestBst(Node* root) {
        return findBST(root).mxsize;
    }
};
