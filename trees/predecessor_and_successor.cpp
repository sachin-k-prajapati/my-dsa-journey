/*
 * Problem: Predecessor and Successor in BST
 * Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
 *
 * Definition:
 * - Given the root of a Binary Search Tree (BST) and a key, find:
 *   - Inorder Predecessor: Largest value smaller than the key.
 *   - Inorder Successor: Smallest value larger than the key.
 * - If predecessor or successor doesn’t exist, return NULL for that.
 *
 * Example:
 * Input: root = [8,1,9,null,4,null,10,3], key = 8
 * Output: 4 9
 *
 * Constraints:
 * - 1 <= nodes <= 1e5
 * - 1 <= node->data, key <= 1e6
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * 1. Use BST properties to search for the key while tracking potential predecessor/successor.
 *    - If current->data > key, current node can be a successor → move left.
 *    - If current->data < key, current node can be a predecessor → move right.
 * 2. If the key node is found:
 *    - Predecessor = rightmost node of its left subtree.
 *    - Successor   = leftmost node of its right subtree.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(H), where H = height of tree. Worst case O(N) if skewed.
 * - Space Complexity: O(1), only using pointers (excluding recursion).
 * - Works directly during BST traversal without extra storage or full inorder traversal.
 * - Handles all edge cases:
 *   - Key is smallest → no predecessor.
 *   - Key is largest → no successor.
 *   - Key not found → predecessor/successor tracked during traversal.
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - BST property allows efficient search:
 *   - Going left → all nodes on the right are larger, so keep them as successor candidates.
 *   - Going right → all nodes on the left are smaller, so keep them as predecessor candidates.
 * - When at the key, predecessor must be the largest in its left subtree,
 *   successor must be the smallest in its right subtree.
 * - This avoids storing inorder traversal and gives optimal performance.
 */

#include <bits/stdc++.h>
using namespace std;

/* BST Node */
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pred = NULL;  // To store predecessor
        Node* succ = NULL;  // To store successor
        Node* curr = root;

        // Traverse the BST to find key and track predecessor/successor
        while (curr) {
            if (curr->data > key) {
                // Current node is a potential successor
                succ = curr;
                curr = curr->left;
            } else if (curr->data < key) {
                // Current node is a potential predecessor
                pred = curr;
                curr = curr->right;
            } else {
                // Found the key node
                // Find predecessor = rightmost of left subtree
                if (curr->left) {
                    Node* rightMost = curr->left;
                    while (rightMost->right) {
                        rightMost = rightMost->right;
                    }
                    pred = rightMost;
                }
                // Find successor = leftmost of right subtree
                if (curr->right) {
                    Node* leftMost = curr->right;
                    while (leftMost->left) {
                        leftMost = leftMost->left;
                    }
                    succ = leftMost;
                }
                break; // Done after processing key
            }
        }

        // Return result as vector of Node pointers [predecessor, successor]
        vector<Node*> result;
        result.push_back(pred);
        result.push_back(succ);
        return result;
    }
};
