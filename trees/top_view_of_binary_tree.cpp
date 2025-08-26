/********************************************************************************************
* Problem: Top View of Binary Tree (GFG)
* Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
* Difficulty: Medium
* Accuracy: ~38%
* 
* Problem Statement:
* You are given a binary tree, and your task is to return its top view. 
* The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
* 
* Notes:
* - Return the nodes from the leftmost node to the rightmost node.
* - If two nodes are at the same horizontal distance (HD), the first node encountered 
*   in level-order traversal (i.e., topmost node) is part of the top view.
* 
* Examples:
* Input: root[] = [1, 2, 3]
* Output: [2, 1, 3]
* 
* Input: root[] = [10, 20, 30, 40, 60, 90, 100]
* Output: [40, 20, 10, 30, 100]
* 
* Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
* Tree:
*        1
*      /   \
*     2     3
*      \   
*       4
*        \
*         5
*          \
*           6
* Output: [2, 1, 3, 6]
* 
********************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        // Queue for BFS: stores pairs of (node, horizontal_distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        // Map to store the first node encountered at each horizontal distance
        map<int, int> mp;
        
        // BFS traversal
        while (!q.empty()) {
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            // If this horizontal distance is encountered for the first time
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }
            
            // Traverse left and right children with updated horizontal distance
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        // Extract nodes in order of horizontal distance (sorted by map)
        for (auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};

/********************************************************************************************
* Explanation of Approach:
* 
* 1. Each node has a horizontal distance (HD) from the root:
*    - Root node has HD = 0.
*    - Left child has HD = parent_HD - 1.
*    - Right child has HD = parent_HD + 1.
* 
* 2. Perform BFS traversal:
*    - For each node, record its HD.
*    - If this HD hasn’t been seen before, store the node’s value 
*      (since BFS ensures the first seen node is the topmost one).
* 
* 3. Finally, sort nodes by HD (using map) and return them.
* 
* Example Walkthrough:
* Input: [1, 2, 3, N, 4, N, N, N, 5, N, 6]
* 
* HD map (first seen at each HD):
* -2 → 2
* -1 → 1
*  0 → 3
*  2 → 6
* 
* Answer: [2, 1, 3, 6]
* 
********************************************************************************************/

/********************************************************************************************
* Time Complexity:
* - O(N log N): Each of N nodes is processed once (BFS = O(N)) and inserted into a map 
*   (O(log N) per insertion).
* 
* Space Complexity:
* - O(N): For storing queue (BFS) + map.
* 
********************************************************************************************/
