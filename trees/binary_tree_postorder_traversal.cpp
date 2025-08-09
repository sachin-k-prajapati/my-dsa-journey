/*
    ------------------------------------------------------------
    Problem: 145. Binary Tree Postorder Traversal
    Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
    ------------------------------------------------------------

    -------------------------------
    Short Problem Statement:
    -------------------------------
    Given the root of a binary tree, return the **postorder** traversal of its nodes' values.

    Postorder Traversal Order:
        1. Traverse the left subtree.
        2. Traverse the right subtree.
        3. Visit the current node.

    Example:
        Input:  root = [1,null,2,3]
        Output: [3,2,1]

    -------------------------------
    Constraints:
    -------------------------------
        - 0 <= N <= 100
        - Node values range: -100 <= Node.val <= 100
        - Follow-up: Can you do it iteratively?

    ------------------------------------------------------------
    Approach & Intuition:
    ------------------------------------------------------------
    1. **Recursive Approach (Trivial)**
        - Natural definition of postorder.
        - Recursively visit left, then right, then current node.
        - Time: O(N) | Space: O(H) recursion stack.

    2. **Iterative Approach (1 Stack, Visited Set)**
        - Use stack to simulate recursion.
        - Keep track of visited nodes to know when to process them.
        - Steps:
            - Push root, go as deep left as possible, pushing right children later.
            - If a node is seen for the first time, push children.
            - If seen again, process it (postorder point).

    3. **Iterative Approach (2 Stacks)**
        - First stack: normal preorder variant (root → right → left).
        - Second stack: reverse of preorder → results in postorder.
        - Time: O(N) | Space: O(N) due to two stacks.

    ------------------------------------------------------------
    Important Points:
    ------------------------------------------------------------
    - Postorder is tricky iteratively because the "visit current" happens after *both* subtrees.
    - **1 Stack** method is space-optimized but more complex to understand.
    - **2 Stack** method is very intuitive (reverse of modified preorder).
    - Works for skewed trees and handles empty input cleanly.

    ------------------------------------------------------------
    Time & Space Complexity (All Approaches):
    ------------------------------------------------------------
    - Time: O(N) — every node visited once.
    - Space:
        Recursive: O(H)
        1 Stack: O(N) worst case
        2 Stacks: O(N)
*/

#include <vector>
#include <stack>
#include <set>
using namespace std;

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

class Solution {
public:
    /* ------------------------------
       Approach 1: Recursive (Simple)
       ------------------------------ */
    void helper(TreeNode* root, vector<int>& postOrder) {
        if (!root) return;                     // Base case
        helper(root->left, postOrder);         // Left subtree
        helper(root->right, postOrder);        // Right subtree
        postOrder.push_back(root->val);        // Process current node
    }

    vector<int> postorderTraversal_recursive(TreeNode* root) {
        vector<int> postOrder;
        helper(root, postOrder);
        return postOrder;
    }

    /* ---------------------------------------
       Approach 2: Iterative (1 Stack + Visited)
       --------------------------------------- */
    vector<int> postorderTraversal_oneStack(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s;
        set<TreeNode*> visited; // Tracks nodes whose children are already processed
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            // First time: push children before node itself
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                // Push children first (left then right)
                if (node->right) s.push(node->right);
                if (node->left) s.push(node->left);
            }
            // Second time: process the node
            else {
                result.push_back(node->val);
                s.pop();
            }
        }

        return result;
    }

    /* ------------------------------
       Approach 3: Iterative (2 Stacks)
       ------------------------------ */
    vector<int> postorderTraversal_twoStacks(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        // Modified preorder: root → right → left
        while (!s1.empty()) {
            TreeNode* node = s1.top(); s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        // Reverse of above order gives postorder
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }

        return result;
    }
};
