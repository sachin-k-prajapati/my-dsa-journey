/*
 * =================================================================================================
 * Problem: 543. Diameter of Binary Tree
 * Link: https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Definition:
 * - The diameter is the number of edges in the longest path between any two nodes.
 * - The path may or may not pass through the root.
 * 
 * Examples:
 * Input:  [1,2,3,4,5]
 * Output: 3
 * Explanation: The longest path is [4,2,1,3] or [5,2,1,3], length = 3 edges.
 * 
 * Constraints:
 * - 1 <= number of nodes <= 10⁴
 * - Node values are between -100 and 100
 * 
 * =================================================================================================
 * APPROACH:
 * - The diameter can be computed by finding, for every node:
 *      height(left subtree) + height(right subtree)
 * - The height of a node = 1 + max(height(left), height(right))
 * - We can calculate height and update diameter at the same time using DFS.
 * 
 * KEY IDEA:
 * - Each recursive call returns the height of the current node.
 * - At each node:
 *      1. Recursively get the left and right heights.
 *      2. Update the diameter as max(diameter, left + right).
 *      3. Return 1 + max(left, right) to the caller.
 * 
 * =================================================================================================
 * COMPLEXITY:
 * - Time: O(n) — each node visited once.
 * - Space: O(h) — recursion stack, where h = tree height.
 *      Worst case: O(n) for skewed tree, O(log n) for balanced tree.
 * =================================================================================================
 */

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

// include header files
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function that returns height of the subtree rooted at `root`
    // and updates the diameter reference.
    int diameterHelper(TreeNode* root, int& diameter) {
        if (!root) return 0; // Base case: empty tree has height 0

        // Recursively compute heights of left and right subtrees
        int leftHeight = diameterHelper(root->left, diameter);
        int rightHeight = diameterHelper(root->right, diameter);
        
        // Update diameter: path through current node = leftHeight + rightHeight
        diameter = max(diameter, leftHeight + rightHeight);

        // Height of current node = 1 + max(left, right)
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Will store the maximum diameter found
        diameterHelper(root, diameter);
        return diameter;
    }
};

/*
 * -------------------------------------------------------------------------------------------------
 * EXAMPLE WALKTHROUGH:
 * Tree: [1,2,3,4,5]
 *
 *             1
 *           /   \
 *          2     3
 *         / \
 *        4   5
 *
 * Post-order traversal steps:
 * - Node 4: left=0, right=0 → diameter = max(0, 0+0=0), height=1
 * - Node 5: left=0, right=0 → diameter = max(0, 0+0=0), height=1
 * - Node 2: left=1, right=1 → diameter = max(0, 1+1=2), height=2
 * - Node 3: left=0, right=0 → diameter = max(2, 0+0=0), height=1
 * - Node 1: left=2, right=1 → diameter = max(2, 2+1=3), height=3
 *
 * Final diameter = 3 (edges in longest path)
 * -------------------------------------------------------------------------------------------------
 */
