/*
🔗 Problem Link: https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

=========================================================================================
94. Convert Min Heap to Max Heap
Difficulty: Medium | Accuracy: ~55%

📝 Problem Statement:
You are given an array arr of N integers representing a **Min Heap**. 
Your task is to convert it into a **Max Heap**.

📌 Definitions:
- Min Heap: A complete binary tree where the parent is always smaller than its children.
- Max Heap: A complete binary tree where the parent is always greater than or equal to its children.

You must transform the given Min Heap into a valid Max Heap **in-place**.

-----------------------------------------------------------------------------------------
🔒 Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^9

⚡ Expected Time Complexity: O(N log N)
⚡ Expected Auxiliary Space: O(1)

-----------------------------------------------------------------------------------------
📊 Examples:

Example 1:
Input:
N = 4
arr = [1, 2, 3, 4]

Output:
[4, 2, 3, 1]

Explanation:
The given Min Heap → Max Heap after conversion.

-----------------------------------------

Example 2:
Input:
N = 5
arr = [3, 4, 8, 11, 13]

Output:
[13, 11, 8, 3, 4]

=========================================================================================
💡 Intuition:
We are given a valid Min Heap but need to rearrange it to satisfy Max Heap properties.
The most efficient way is to perform a **Heapify Down** process starting from the last
non-leaf node down to the root.

- For every node i (from bottom to top):
  - Compare it with its left & right children.
  - Swap it with the largest child if heap property is violated.
  - Keep "heapifying down" until the subtree satisfies Max Heap property.

This process is similar to **building a max heap** from an array.

-----------------------------------------------------------------------------------------
✅ Approach:
1. Start from the last internal node `(N-2)/2` and move upward.
2. For each node, apply heapify to ensure subtree rooted at that node is a max heap.
3. Continue until the root is processed.
4. The array now represents a valid Max Heap.

=========================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert given Min Heap to Max Heap
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // Start from last non-leaf node and heapify upwards
        for (int i = (N-2)/2; i >= 0; i--) {
            int j = i;
            
            // Heapify down for current node
            while (j >= 0) {
                int largest = j;
                int left = 2 * j + 1;
                int right = 2 * j + 2;
                
                // Check left child
                if (left < N && arr[left] > arr[largest]) {
                    largest = left;
                }
                // Check right child
                if (right < N && arr[right] > arr[largest]) {
                    largest = right;
                }
                
                // If heap property violated, swap and continue heapifying
                if (largest != j) {
                    swap(arr[j], arr[largest]);
                    j = largest; // move to swapped child
                } else break; // heap property satisfied
            }
        }
    }
};

/*
=========================================================================================
🕵️ Notes:
- This process ensures O(N log N) complexity since heapify for each node takes O(log N).
- Array is modified in place, so no extra space needed (O(1)).
- This is the standard approach used in heap-based sorting/building operations.

-----------------------------------------------------------------------------------------
📌 Dry Run Example:

Input: [1, 2, 3, 4]
Step 1: Start heapify from index 1 → swap with 4 → arr = [1, 4, 3, 2]
Step 2: Heapify index 0 → swap with 4 → arr = [4, 1, 3, 2] → then swap 1 and 2
Final: [4, 2, 3, 1]

=========================================================================================
*/
