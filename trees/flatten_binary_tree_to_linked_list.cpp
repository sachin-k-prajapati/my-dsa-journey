/*
 * =================================================================================================
 * Problem: 
 * 114. Flatten Binary Tree to Linked List
 * LINK: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * Problem Statement:
 * Given the root of a binary tree, flatten it into a "linked list" in-place.
 * - The "linked list" should use the same TreeNode structure.
 * - Right pointer should point to the next node in preorder traversal.
 * - Left pointer should always be NULL.
 *
 * Example:
 * Input:  [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 *
 * Constraints:
 * - 0 <= Number of nodes <= 2000
 * - Node values range from -100 to 100
 * - Flatten in-place (O(1) extra space) if possible.
 * =================================================================================================
 *
 * GENERAL NOTES FOR SIMILAR PROBLEMS:
 * - Always clarify which traversal order (preorder/inorder/postorder) is required.
 * - For "in-place" modification, think of **pointer rewiring** rather than data copying.
 * - O(1) extra space usually means no recursion or extra containers → use iterative methods.
 * - Always test on skewed trees (all left or all right) for pointer safety.
 * - Finding the rightmost node repeatedly can cause O(n²) worst case complexity.
 *
 * =================================================================================================
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* -------------------------------------------------------------------------------------------------
   SOLUTION 1: Recursive Helper Method
   -------------------------------------------------------------------------------------------------
   Approach:
   - Perform a recursive DFS.
   - For each node:
       1. If it has a left child:
           - Save the current right subtree.
           - Move the left subtree to the right pointer.
           - Set left pointer to NULL.
           - Traverse to the rightmost node of the moved left subtree.
           - Attach the saved right subtree at the end.
       2. Recursively flatten the right subtree.
   - This approach mimics the "preorder" structure manually.
   
   Complexity:
   - Time: O(n²) in worst case (due to repeated rightmost searches in skewed trees).
   - Space: O(h) recursion stack space (h = tree height).
   
   Pros:
   - Easy to understand, direct recursive style.
   Cons:
   - Not optimal in worst-case time complexity.
   ------------------------------------------------------------------------------------------------- */

class Solution1 {
public:
    void flatHelper(TreeNode* root){
        if(!root) return; // Base case

        if(root->left){
            TreeNode* temp = root->right; // Store original right subtree
            root->right = root->left;     // Move left subtree to right
            root->left = nullptr;         // Nullify left pointer

            // Find rightmost node of new right subtree
            TreeNode* track = root->right;
            while(track->right){
                track = track->right;
            }
            track->right = temp; // Attach original right subtree
        }

        flatHelper(root->right); // Recurse for right subtree
    }

    void flatten(TreeNode* root) {
        flatHelper(root);
    }
};

/* -------------------------------------------------------------------------------------------------
   SOLUTION 2: Iterative with Temporary Pointer
   -------------------------------------------------------------------------------------------------
   Approach:
   - Start from root, iterate while current node exists.
   - If current node has a left child:
       1. Save the right subtree.
       2. Move left subtree to right.
       3. Set left to NULL.
       4. Traverse to the rightmost node of the moved subtree.
       5. Attach the saved right subtree there.
   - Move to the next right node.
   
   Complexity:
   - Time: O(n²) in worst case for skewed trees (same reason as Solution 1).
   - Space: O(1) (fully iterative, no recursion).
   
   Pros:
   - No recursion, avoids stack space.
   Cons:
   - Still has O(n²) worst-case behavior.
   ------------------------------------------------------------------------------------------------- */

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* temp = curr->right; // Store right subtree
                curr->right = curr->left;     // Move left subtree to right
                curr->left = nullptr;         // Nullify left

                // Find rightmost of the new right subtree
                TreeNode* track = curr->right;
                while(track->right){
                    track = track->right;
                }
                track->right = temp; // Attach original right subtree
            }
            curr = curr->right; // Move to next node
        }
    }
};

/* -------------------------------------------------------------------------------------------------
   SOLUTION 3: Iterative (Pointer Rewiring First)
   -------------------------------------------------------------------------------------------------
   Approach:
   - Similar to Solution 2 but first find the rightmost node of the left subtree.
   - Attach the current node’s right subtree to this rightmost node.
   - Move left subtree to right and nullify left pointer.
   - This reduces some redundant work but still can have O(n²) worst case for skewed trees.
   
   Complexity:
   - Time: O(n²) in worst case (skewed tree) because finding rightmost repeatedly can revisit nodes.
   - Space: O(1).
   
   Pros:
   - Cleaner and slightly more efficient than Solution 2 on average trees.
   Cons:
   - Not truly O(n) unless using Morris Traversal logic.
   ------------------------------------------------------------------------------------------------- */

class Solution3 {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                // Find the rightmost node of the left subtree
                TreeNode* rightMost = curr->left;
                while(rightMost->right){
                    rightMost = rightMost->right;
                }

                // Attach original right subtree to rightmost node
                rightMost->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right; // Continue to next node
        }
    }
};

/*
 * -------------------------------------------------------------------------------------------------
 * COMPARISON TABLE:
 * -------------------------------------------------------------------------------------------------
 * | Solution   | Approach Type | Time Complexity (worst) | Space Complexity | Pros                           | Cons                                |
 * |------------|--------------|------------------------|-----------------|--------------------------------|-------------------------------------|
 * | Solution 1 | Recursive    | O(n²)                   | O(h)            | Simple, easy to follow         | Slow for skewed trees               |
 * | Solution 2 | Iterative    | O(n²)                   | O(1)            | No recursion, in-place         | Still slow in worst case            |
 * | Solution 3 | Iterative    | O(n²)                   | O(1)            | Cleaner than Solution 2        | Still O(n²) worst case without Morris|
 * -------------------------------------------------------------------------------------------------
 *
 * NOTE: For guaranteed O(n) time and O(1) space, use Morris Traversal-based solution.
 */
