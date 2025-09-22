/*
 * Problem: Ceil in BST
 * Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
 *
 * Definition:
 * - Given a Binary Search Tree (BST) and an integer x, find its "ceil".
 * - Ceil(x) = smallest element in BST >= x.
 * - If no such element exists, return -1.
 *
 * Examples:
 * Input: root = [5,1,7,null,2], x = 3 → Output: 3
 * Input: root = [10,5,11,4,7,null,null,null,null,null,8], x = 6 → Output: 7
 *
 * Constraints:
 * - 1 ≤ number of nodes ≤ 1e5
 * - 1 ≤ node->data ≤ 1e5
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * 1. Use BST properties to efficiently search:
 *    - If node->data >= x → candidate ceil, but check left subtree for smaller valid value.
 *    - If node->data < x  → move right since ceil must be larger.
 * 2. If no valid ceil is found, return -1.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(H), H = height of BST. Worst O(N) if skewed, best O(logN).
 * - Space Complexity:
 *   - Code 1 → O(N) due to full recursion (visits all nodes).
 *   - Code 2 → O(H), optimized traversal using BST property.
 * - Ceil definition: number >= x, closest possible.
 * - Edge cases:
 *   - If x is greater than all nodes → return -1.
 *   - If x is smaller than root and exists → return smallest >= x.
 *   - If exact match is found → ceil = x.
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of an inorder traversal (sorted order):
 *   - Ceil(x) = first number in inorder >= x.
 * - Instead of storing full inorder, we exploit BST:
 *   - If node >= x, it’s a potential ceil. Go left to check smaller candidates.
 *   - If node < x, ignore left (too small), go right.
 * - This gives an efficient and elegant solution.
 */

/* BST Node structure */
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


// -----------------------------------------------------------------------------
// Code 1: Brute Force DFS approach (visits every node)
// -----------------------------------------------------------------------------
class Solution {
  public:
    // Helper DFS function to track ceil
    void ceil(Node* root, int x, int& cl) {
        if (!root) return;

        // Update ceil if root->data is valid candidate
        if (root->data >= x && root->data < cl) cl = root->data;

        // Explore both sides (brute force)
        ceil(root->left, x, cl);
        ceil(root->right, x, cl);
    }
    
    int findCeil(Node* root, int x) {
        int cl = INT_MAX;
        ceil(root, x, cl);
        if (cl == INT_MAX) cl = -1; // no ceil found
        return cl;
    }
};

// -----------------------------------------------------------------------------
// Code 2: Optimized BST traversal approach
// -----------------------------------------------------------------------------
class SolutionOptimized {
  public:
    // Helper: use BST property to prune search space
    void ceil(Node* root, int x, int& cl) {
        if (!root) return;

        if (root->data >= x && root->data < cl) {
            cl = root->data; // update candidate ceil
        }

        // Prune search using BST property
        if (root->data > x) ceil(root->left, x, cl);   // smaller possible ceil on left
        else if (root->data < x) ceil(root->right, x, cl); // must go right
    }
    
    int findCeil(Node* root, int x) {
        int cl = INT_MAX;
        ceil(root, x, cl);
        if (cl == INT_MAX) cl = -1;
        return cl;
    }
};
