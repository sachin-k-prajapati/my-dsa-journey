/*
    Problem: 144. Binary Tree Preorder Traversal
    Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

    -------------------------------
    Problem Statement:
    -------------------------------
    Given the root of a binary tree, return the preorder traversal of its nodes' values.

    Preorder Traversal Order:
        1. Visit the current node.
        2. Traverse the left subtree.
        3. Traverse the right subtree.

    -------------------------------
    Examples:
    -------------------------------
    Example 1:
        Input: root = [1,null,2,3]
        Output: [1,2,3]

    Example 2:
        Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
        Output: [1,2,4,5,6,7,3,8,9]

    Example 3:
        Input: root = []
        Output: []

    -------------------------------
    Constraints:
    -------------------------------
        - The number of nodes in the tree is in the range [0, 100].
        - Node values range from [-100, 100].

    -------------------------------
    Follow-up:
    -------------------------------
        Recursive solution is straightforward. The task asks for an iterative solution.

    -------------------------------
    Approaches:
    -------------------------------

    1. Recursive (Trivial):
        - Simply call preorderTraversal on left, then right, appending results.
        - Time: O(n)
        - Space: O(h) for recursion stack.

    2. Iterative (Our Approach):
        - Use a stack to simulate recursion.
        - Push root into the stack.
        - While stack is not empty:
            - Pop the top node, process its value.
            - Push right child first, then left child (so left is processed first).
        - Time: O(n) — every node is processed exactly once.
        - Space: O(n) — worst-case stack space for skewed tree.

    -------------------------------
    Key Points:
    -------------------------------
    - Pushing right first ensures left subtree is processed first in preorder.
    - Avoids recursion depth limits for very deep trees.

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

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        // Edge case: empty tree
        if (!root) return result;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            // Process the current node
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);

            // Push right child first so left child is processed first
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        return result;
    }
};

// ----------------------------------------------------------------------------
// Recursive Approach
void preorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderHelper(root->left, result);
    preorderHelper(root->right, result);
}