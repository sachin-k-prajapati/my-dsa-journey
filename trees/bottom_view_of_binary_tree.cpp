/*
🔹 Problem: Bottom View of Binary Tree
   Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
   Difficulty: Medium

📖 Problem Statement:
You are given a binary tree, and your task is to return its bottom view. 
The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: 
- If there are multiple bottom-most nodes for the same horizontal distance (HD), 
  the one appearing later in level order traversal (BFS) should be considered.

Example:
Input:  root[] = [10, 20, 30, 40, 60]
Output: [40, 20, 60, 30]

Explanation:
- Horizontal Distance (HD) mapping:
    HD -2 → 40
    HD -1 → 20
    HD  0 → 60   (overwrites 10 because 60 is lower in level order)
    HD +1 → 30
=> Final bottom view: 40 20 60 30

---------------------------------------------------
⚡ Intuition:
- Each node has a "horizontal distance" (HD) from the root:
   - Root → HD = 0
   - Left child → HD - 1
   - Right child → HD + 1
- Perform BFS (level order traversal) so deeper nodes overwrite previous nodes at the same HD.
- Store mapping {HD → node->data}.
- After traversal, extract values from leftmost HD to rightmost HD.

---------------------------------------------------
🛠️ Approach (Step by Step):
1. Initialize a queue for BFS storing {node, horizontal distance}.
2. Maintain a map<int, int> where:
   - key = HD
   - value = latest node’s value at that HD (ensures bottommost due to BFS).
3. Push root with HD = 0.
4. For each node:
   - Pop from queue.
   - Update map[HD] = node->data (latest node overwrites).
   - Push left child with HD-1, right child with HD+1.
5. Extract results from map (ordered by HD).
6. Return the list.

---------------------------------------------------
⏱️ Complexity:
- Time: O(N log N) → because we visit N nodes, and each insertion in map takes O(log N).
- Space: O(N) → for queue + map.

---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/* Structure for a binary tree node */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        // Queue for BFS → stores {node, horizontal distance}
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        // Map to store {HD → node->data}
        map<int, int> mp;
        
        while (!q.empty()) {
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            // Update mapping (latest node at same HD overwrites)
            mp[hd] = node->data;
            
            // Push children with updated HD
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        // Collect results from leftmost to rightmost HD
        for (auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};

/*
---------------------------------------------------
✅ Example Walkthrough:
Tree: [10, 20, 30, 40, 60]
        10
       /  \
     20    30
    /  \
   40  60

- Start: q = {(10,0)}
- Process 10 → mp[0]=10 → push {(20,-1), (30,1)}
- Process 20 → mp[-1]=20 → push {(40,-2), (60,0)}
- Process 30 → mp[1]=30
- Process 40 → mp[-2]=40
- Process 60 → mp[0]=60 (overwrites 10)

Final map: {-2:40, -1:20, 0:60, 1:30}
=> Bottom view = [40,20,60,30]
---------------------------------------------------
*/
