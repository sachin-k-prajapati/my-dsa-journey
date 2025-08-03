// Problem: Sum Root to Leaf Numbers [Given a binary tree containing digits 0-9 only, each root-to-leaf path could represent a number. Return the total sum of all root-to-leaf numbers.]
// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

#include <iostream>
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
    // Helper function to traverse tree and compute path sums
    void sumRootToLeaf(TreeNode* root, int& rootleafsum, int left, int right){
        // If this is a leaf node, add path sum to result
        if (!root->left && !root->right){
            rootleafsum += left; // or right (both are always equal here)
            return;
        }

        // Update values for left and right child
        left *= 10;
        if (root->left) left += root->left->val;

        right *= 10;
        if (root->right) right += root->right->val;

        // Recurse into child nodes
        if (root->left) sumRootToLeaf(root->left, rootleafsum, left, left);
        if (root->right) sumRootToLeaf(root->right, rootleafsum, right, right);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumRootToLeaf(root, sum, root->val, root->val);

        if (!sum) return root->val; // single node case
        return sum;
    }
};

/*
Approach:
- Use DFS to traverse all root-to-leaf paths
- Build numbers by multiplying current value by 10 and adding next digit
- Accumulate total when reaching leaf nodes

Time: O(N), where N is number of tree nodes
Space: O(H), where H is height of the tree

Notes:
- Builds path numbers digit-by-digit during traversal
- Handles edge case of single node tree
- Uses pass-by-reference to accumulate the total sum
*/
