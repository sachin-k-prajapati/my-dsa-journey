/*
Problem: Minimum Cost to Move Between Indices
Link: https://leetcode.com/problems/minimum-cost-to-move-between-indices/

Definition:
Given a strictly increasing array nums, you can move from index x to:
1. Any index y → cost = |nums[x] - nums[y]|
2. closest(x) → cost = 1

For each query [l, r], find minimum cost to move from l → r.

------------------------------------------------------------

Approach:

Precomputation + Prefix Sum Optimization

Key Idea:
Movement is always optimal through ADJACENT indices.

Why?
→ Direct jump cost = |nums[x] - nums[y]| (large)
→ Multiple "closest moves" cost = 1 each (often cheaper)

------------------------------------------------------------

Step 1: Find closest index for each position

For each i:
    compare:
        left  = |nums[i] - nums[i-1]|
        right = |nums[i] - nums[i+1]|

    choose smaller (tie → left)

------------------------------------------------------------

Step 2: Build prefix arrays

Two directions:

1. prefixRight[i]
    → cost to move from 0 → i

2. prefixLeft[i]
    → cost to move from i → 0

------------------------------------------------------------

Transition Logic:

Moving i → i+1:
    if closest(i) == i+1 → cost = 1
    else → cost = abs(nums[i+1] - nums[i])

Moving i → i-1:
    if closest(i) == i-1 → cost = 1
    else → cost = abs(nums[i] - nums[i-1])

------------------------------------------------------------

Step 3: Answer queries

If l < r:
    answer = prefixRight[r] - prefixRight[l]

Else:
    answer = prefixLeft[l] - prefixLeft[r]

------------------------------------------------------------

Why this works:

We precompute cheapest adjacent transitions,
so any range query becomes O(1).

------------------------------------------------------------

Key Points:

Time Complexity: O(N + Q)
Space Complexity: O(N)

------------------------------------------------------------

Edge Cases:

- l == r → cost = 0
- n = 2 → simple direct move
- equal differences → choose left

------------------------------------------------------------

Deep Intuition:

We convert problem into:

"Minimum cost to move step-by-step"

Instead of jumping randomly,
we simulate optimal local decisions
and store them using prefix sums.

------------------------------------------------------------

Pattern:

Greedy + Prefix Sum + Range Query Optimization

------------------------------------------------------------
*/
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        // Step 1: Find closest index for each position
        vector<int> isSisterCity(n);

        isSisterCity[0] = 1;

        for (int i = 1; i < n - 1; i++) {
            int left = abs(nums[i] - nums[i - 1]);
            int right = abs(nums[i] - nums[i + 1]);

            if (left <= right) isSisterCity[i] = i - 1;
            else isSisterCity[i] = i + 1;
        }

        isSisterCity[n - 1] = n - 2;

        // Step 2: Prefix for moving LEFT (i → 0)
        vector<int> prefixLeft(n, 0);

        for (int i = 1; i < n; i++) {

            int minCost = 0;

            // If closest(i) is left → cheap move
            if (isSisterCity[i] == i - 1)
                minCost = 1;
            else
                minCost = abs(nums[i] - nums[i - 1]);

            prefixLeft[i] = prefixLeft[i - 1] + minCost;
        }

        // Step 3: Prefix for moving RIGHT (0 → i)
        vector<int> prefixRight(n, 0);

        for (int i = 0; i < n - 1; i++) {

            int minCost = 0;

            // If closest(i) is right → cheap move
            if (isSisterCity[i] == i + 1)
                minCost = 1;
            else
                minCost = abs(nums[i + 1] - nums[i]);

            prefixRight[i + 1] = prefixRight[i] + minCost;
        }

        // Step 4: Answer queries
        vector<int> result;

        for (vector<int> q : queries) {

            int starting = q[0];
            int ending = q[1];

            // Move forward
            if (starting < ending) {
                result.push_back(prefixRight[ending] - prefixRight[starting]);
            }
            // Move backward
            else {
                result.push_back(prefixLeft[starting] - prefixLeft[ending]);
            }
        }

        return result;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Prefix Sum + Greedy Local Transitions

------------------------------------------------------------

Core Idea:

Reduce problem into:
"Cost of moving step-by-step"

------------------------------------------------------------

Why prefix sum?

To answer each query in O(1)

------------------------------------------------------------

Key Trick:

Precompute:
→ cheapest adjacent moves

------------------------------------------------------------

Important Insight:

Closest move = cost 1
Normal move = abs difference

------------------------------------------------------------

Common Mistakes:

❌ Trying Dijkstra / BFS (too slow)
❌ Ignoring sorted property
❌ Not handling both directions separately
❌ Forgetting prefix subtraction

------------------------------------------------------------

Interview Line:

"Precompute optimal adjacent moves and use prefix sums for fast queries."

------------------------------------------------------------

Mental Model:

Convert complex movement into:
simple linear transitions

------------------------------------------------------------
*/