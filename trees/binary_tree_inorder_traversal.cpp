/*
    ------------------------------------------------------------
    Problem: 94. Binary Tree Inorder Traversal
    Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
    ------------------------------------------------------------

    -------------------------------
    Problem Statement:
    -------------------------------
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Inorder Traversal Order:
        1. Traverse the left subtree.
        2. Visit the current node.
        3. Traverse the right subtree.

    -------------------------------
    Examples:
    -------------------------------
    Example 1:
        Input: root = [1,null,2,3]
        Output: [1,3,2]

    Example 2:
        Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
        Output: [4,2,6,5,7,1,3,9,8]

    Example 3:
        Input: root = []
        Output: []

    Example 4:
        Input: root = [1]
        Output: [1]

    -------------------------------
    Constraints:
    -------------------------------
        - Number of nodes: 0 <= N <= 100
        - Node value range: -100 <= Node.val <= 100

    -------------------------------
    Follow-up:
    -------------------------------
        Recursive approach is trivial; can you implement it iteratively?

    ------------------------------------------------------------
    Approach & Intuition:
    ------------------------------------------------------------
    1. Recursive Traversal (Trivial):
        - Base case: null node → return
        - Visit left subtree → current node → right subtree
        - Time: O(N)
        - Space: O(H) recursion stack

    2. Iterative Traversal (Chosen Approach):
        - Idea: Use a stack to simulate recursion
        - Standard iterative inorder uses:
            - Pushing left nodes until null
            - Processing top node
            - Moving to right subtree
        - This implementation uses:
            - Stack + visited set to handle processing order
            - Push order: right child → node itself → left child
            - When visiting node second time (found in visited), add to result.

    ------------------------------------------------------------
    Why This Works:
    ------------------------------------------------------------
    - First time encountering a node → we haven't processed its left subtree.
    - We push right first so it’s processed later, then node, then left child.
    - Second time encountering the same node → its left subtree is already processed, so now we add its value.

    ------------------------------------------------------------
    Time & Space Complexity:
    ------------------------------------------------------------
    - Time: O(N) — each node is processed twice at most.
    - Space: O(N) — stack + visited set in worst case.

    ------------------------------------------------------------
    Important Points:
    ------------------------------------------------------------
    - Simulates recursion without explicit pointer movement variables.
    - Works even if left or right subtrees are missing.
    - Handles empty tree gracefully.

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
#include <set>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (!root) return result; // Empty tree

        stack<TreeNode*> s;
        s.push(root);
        set<TreeNode*> visited; // Tracks nodes whose left subtree is already processed

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            // First time seeing this node → push in processing order
            if (visited.find(node) == visited.end()) {
                visited.insert(node); // Mark as visited
                
                if (node->right) s.push(node->right); // Right child will be processed later
                s.push(node);                         // Node itself (for processing after left)
                if (node->left) s.push(node->left);   // Left child comes first in inorder
            }
            // Second time seeing this node → process it
            else {
                result.push_back(node->val);
            }
        }

        return result;
    }
};

// ----------------------------------------------------------------------------
// Recursive Approach
void inorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderHelper(root->left, result);
    result.push_back(root->val);
    inorderHelper(root->right, result);
}