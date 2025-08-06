// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (!root) return rightView;

        // Rightmost node of level 0 is always the root
        rightView.push_back(root->val);
        int visited = 0;  // Keeps track of last visited level

        queue<pair<TreeNode*, int>> Q;

        // Push right child first to ensure rightmost nodes are processed first
        if (root->right) Q.push({root->right, 1});
        if (root->left) Q.push({root->left, 1});

        while (!Q.empty()) {
            TreeNode* temp = Q.front().first;
            int level = Q.front().second;
            Q.pop();

            // If entering a new level, add the first node (rightmost) to the result
            if (level != visited) {
                rightView.push_back(temp->val);
                visited = level;
            }

            // Again push right first to prioritize right-side view
            if (temp->right) Q.push({temp->right, level + 1});
            if (temp->left) Q.push({temp->left, level + 1});
        }

        return rightView;
    }
};

/*
Approach:
- Use BFS (level-order traversal) with a queue to traverse each level
- Prioritize right child while enqueueing nodes to ensure rightmost nodes are visited first
- Track current level using a `visited` variable to detect when a new level is encountered

Time: O(N), where N is the number of nodes
Space: O(W), where W is the maximum width of the tree (queue usage)

Notes:
- Returns the rightmost node at each level of the binary tree
- Handles empty tree case
- Efficiently tracks levels using a pair of node and level in queue
*/
