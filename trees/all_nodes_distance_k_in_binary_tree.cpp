/*
==========================================================
Problem: 863. All Nodes Distance K in Binary Tree
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Description:
------------
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Constraints:
------------
- The number of nodes in the tree is in the range [1, 500].
- 0 <= Node.val <= 500
- All the values Node.val are unique.
- target is the value of one of the nodes in the tree.
- 0 <= k <= 1000

Example 1:
----------
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]

Example 2:
----------
Input: root = [1], target = 1, k = 3
Output: []

==========================================================
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


///////////////////////////////////////////////////////////
// First Approach
// --------------------------------------------------------
// Recursive DFS approach without extra space for parent mapping
// The idea:
// 1. Perform DFS from root to find the target node.
// 2. When the target is found, use a helper DFS to collect nodes at distance k downward.
// 3. As recursion unwinds, calculate the distance from the current node to target.
// 4. If the target lies in one subtree, check the opposite subtree for remaining distance.
// 
// Time Complexity: O(N) — Each node visited at most once.
// Space Complexity: O(H) — Recursion stack, where H = height of tree.
///////////////////////////////////////////////////////////

class Solution {
public:
    // Finder function: searches for target and handles distances on the way back
    void finder(TreeNode* root, TreeNode* target, int k, vector<int>& result, bool& find, int& steps){
        if (!root) return;

        // Target node found
        if(root == target) {
            helper(target, k, result, steps); // collect nodes k distance downwards
            steps++;
            find = true;
            return;
        }

        // Search in left subtree
        if(root->left) {
            finder(root->left, target, k, result, find, steps);
            if(find) { // If found in left subtree
                if ((steps) == k) { // Current node is at distance k
                    result.push_back(root->val);
                    steps++;
                }
                else helper(root->right, k, result, ++steps); // search in opposite subtree
                return;
            }
        }
        
        // Search in right subtree
        if(root->right) {
            finder(root->right, target, k, result, find, steps);
            if(find) { // If found in right subtree
                if ((steps) == k) { // Current node is at distance k
                    result.push_back(root->val);
                    steps++;
                }
                else helper(root->left, k, result, ++steps); // search in opposite subtree
                return;
            }
        }
    }

    // Helper function: DFS to collect nodes k distance below given node
    void helper(TreeNode* target, int k, vector<int>& result, int steps) {
        if(!target) return;

        if(steps == k) {
            result.push_back(target->val);
            return;
        }

        if(target->left) helper(target->left, k, result, steps+1);
        if(target->right) helper(target->right, k, result, steps+1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> distanceNodes;
        bool find = false; // flag if target found
        int steps = 0;     // distance from target
        finder(root, target, k, distanceNodes, find, steps);
        return distanceNodes;
    }
};

///////////////////////////////////////////////////////////
// Second Approach (Optimized BFS + Parent Map)
// --------------------------------------------------------
// Idea:
// 1. Preprocess the tree to create a map of child->parent relationships.
// 2. Perform BFS starting from target node, traversing left, right, and parent.
// 3. Keep track of visited nodes to avoid cycles.
// 4. Stop BFS when we reach distance k and collect all nodes.
//
// Time Complexity: O(N) — BFS visits each node once.
// Space Complexity: O(N) — Parent map + visited set + BFS queue.
///////////////////////////////////////////////////////////

class Solution {
public:
    // Build map from node to its parent
    void buildParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!root) return;

        if (root->left){
            parentMap.insert({root->left, root});
            buildParentMap(root->left, parentMap);
        }
        if (root->right){
            parentMap.insert({root->right, root});
            buildParentMap(root->right, parentMap);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, parentMap); // step 1: build parent links

        vector<int> result;
        queue<pair<TreeNode*, int>> Q;
        Q.push({target, 0});

        set<TreeNode*> visited; // to avoid revisiting nodes

        while(!Q.empty()) {
            TreeNode* node = Q.front().first;
            int distance = Q.front().second;
            Q.pop();

            if (visited.find(node) == visited.end()) {
                visited.insert(node);

                if (distance == k) {
                    result.push_back(node->val);
                }
                
                if (distance > k) break; // optimization: stop when distance exceeded

                // Push all possible moves
                if (node->left) Q.push({node->left, distance+1});
                if (node->right ) Q.push({node->right, distance+1});
                if (parentMap.find(node) != parentMap.end()) Q.push({parentMap[node], distance+1});
            }
        }

        return result;
    }
};

/*
==========================================================
Notes:
------
- First approach is pure DFS with backtracking logic; avoids extra space for parent pointers but is slightly trickier to implement.
- Second approach is more standard BFS after building parent relationships; generally easier to maintain.
- Both achieve O(N) time complexity and work within given constraints.
==========================================================
*/
