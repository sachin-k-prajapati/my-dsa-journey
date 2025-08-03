// Linked List in Binary Tree

/*
 * Problem:
 * Given a binary tree root and a linked list with head as the first node, return true if 
 * all the elements in the linked list starting from the head correspond to some downward 
 * path connected in the binary tree.
 *
 * Link: https://leetcode.com/problems/linked-list-in-binary-tree/
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    // Step 1: Find all TreeNodes with the same value as the linked list head
    void helper(TreeNode* root, int headValue, vector<TreeNode*>& rootsVector) {
        if (!root) return;

        if (root->val == headValue)
            rootsVector.push_back(root);

        helper(root->left, headValue, rootsVector);
        helper(root->right, headValue, rootsVector);
    }

    // Step 2: Check if the path matches from current TreeNode down the tree
    void check(TreeNode* root, ListNode* temp, bool& flag) {
        if (!temp) {
            flag = true;
            return;
        }

        if (!root) return;

        if (root->val == temp->val) {
            check(root->left, temp->next, flag);
            check(root->right, temp->next, flag);
        }
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> rootsVector;
        helper(root, head->val, rootsVector);

        while (!rootsVector.empty()) {
            ListNode* temp = head;
            TreeNode* sameRoot = rootsVector.back();
            rootsVector.pop_back();

            bool trace = false;
            check(sameRoot, temp, trace);

            if (trace)
                return true;
        }

        return false;
    }
};

/*
Approach:
- Step 1: Collect all the nodes in the binary tree that match the head of the linked list.
- Step 2: For each of these starting nodes, check whether we can follow the list down the tree.
- Uses DFS for both scanning and checking.

Time Complexity: O(N * M)
  - N = total nodes in binary tree
  - M = length of the linked list

Space Complexity: O(H) where H = height of the binary tree

Notes:
- Two-phase approach helps separate responsibilities cleanly.
- Recursive checking ensures all downward paths are evaluated.
- Handles multiple possible matching starting points.
*/
