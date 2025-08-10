/*
====================================================================
    Problem: Boundary Traversal of a Binary Tree
    Source: GeeksforGeeks
    Link: https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
    Difficulty: Medium

    SHORT DEFINITION:
    -----------------
    Traverse the binary tree in this special order:
    1. Left Boundary (excluding leaves)
    2. All Leaf Nodes (L → R)
    3. Reverse Right Boundary (excluding leaves)

    IMPORTANT:
    ----------
    - Left Boundary: Always prefer left child over right child; stop at leaves.
    - Leaf Nodes: Visit all leaves left-to-right (but don't double-count).
    - Right Boundary: Always prefer right child over left child; stop at leaves.
      Finally, reverse this list before adding to result.
    - If the root has no left/right subtree, it itself is part of that boundary.

    WHY THIS MATTERS (INTERVIEW USEFULNESS):
    ----------------------------------------
    This tests understanding of:
      * Tree traversal variations
      * Avoiding duplicate visits
      * Order handling (reverse requirement)
      * Edge case thinking (single node, skewed trees)

====================================================================
    APPROACH INTUITION:
    -------------------
    The traversal is *modular* — we break it into 3 clear helper functions:
      1. leftBoundary()
         - Keep going left if possible; else go right.
         - Stop at leaf nodes (don't include them here).
      2. leafNode()
         - DFS to collect leaves (both left and right subtrees).
      3. rightBoundary()
         - Keep going right if possible; else go left.
         - Stop at leaf nodes; collect in a temporary list, then reverse.

    This modular separation ensures:
      - No duplicates (leaves handled only once)
      - Correct order without backtracking mess
====================================================================
*/

// -------------------- Tree Node Definition --------------------
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// ========================== SOLUTION 1 ==========================
// Recursive Left + Recursive Right + Leaf nodes in between
// Pros: Simple, directly matches problem definition
// Cons: Slightly less clean in edge case handling (extra checks needed)
#include <vector>
using namespace std;

class Solution1 {
  public:
    // Collect left boundary (excluding leaves)
    void leftBoundary(Node* root, vector<int>& result) {
        if (root->left) {
            result.push_back(root->data);
            leftBoundary(root->left, result);
        } else if (root->right) {
            result.push_back(root->data);
            leftBoundary(root->right, result);
        }
        // Stop if it's a leaf (no left/right)
    }
    
    // Collect right boundary (excluding leaves) — postorder to reverse order
    void rightBoundary(Node* root, vector<int>& result) {
        if (root->right) {
            rightBoundary(root->right, result);
            result.push_back(root->data); // Add AFTER recursion for reverse order
        } else if (root->left) {
            rightBoundary(root->left, result);
            result.push_back(root->data);
        }
    }
    
    // Collect all leaf nodes (L → R)
    void leafNode(Node* root, vector<int>& result) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(root->data);
            return;
        }
        if (root->left) leafNode(root->left, result);
        if (root->right) leafNode(root->right, result);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        if (!root) return result;

        result.push_back(root->data); // Root always included (once)
        
        // Left boundary
        if (root->left) leftBoundary(root->left, result);

        // All leaf nodes
        if (root->left || root->right) leafNode(root, result);

        // Right boundary
        if (root->right) rightBoundary(root->right, result);
        
        return result;
    }
};

// ========================== SOLUTION 2 ==========================
// Iterative + Clean Separation + Temporary storage for reverse right boundary
// Pros: Very clean, easy to debug, less recursion depth
// Cons: Slightly more verbose
#include <algorithm>

class Solution2 {
  public:
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            // Skip leaf nodes
            if (curr->left || curr->right) res.push_back(curr->data);
            // Prefer left child
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        vector<int> temp;
        Node* curr = root->right;
        while (curr) {
            if (curr->left || curr->right) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // Add in reverse order
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;

        res.push_back(root->data); // Add root first
        addLeftBoundary(root, res); // Left boundary
        if (root->left || root->right) addLeaves(root, res); // Leaves
        addRightBoundary(root, res); // Right boundary

        return res;
    }
};

/*
====================================================================
COMPLEXITY ANALYSIS:
--------------------
N = number of nodes in tree

Time:  O(N) — every node is visited at most once
Space: O(H) recursion stack for DFS + O(N) output list
       (H = height of tree)

EDGE CASES TO REMEMBER:
-----------------------
1. Single node tree → Only root in result
2. Skewed left tree → Right boundary empty
3. Skewed right tree → Left boundary empty
4. All leaves are also part of boundaries → avoid duplicates
====================================================================
*/
