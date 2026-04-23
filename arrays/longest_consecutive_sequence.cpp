/*
 * Problem: Longest Consecutive Sequence
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Definition:
 * - Given an unsorted array, find the length of the longest sequence
 *   of consecutive integers.
 * - Must be solved in O(N) time.
 *
 * Example:
 * Input: [100,4,200,1,3,2]
 * Output: 4  → sequence: [1,2,3,4]
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Use an unordered_set for O(1) lookup.
 *
 * Steps:
 * 1. Insert all elements into a set.
 * 2. For each number:
 *     - Check if it is the start of a sequence:
 *         (num - 1 NOT in set)
 *     - If yes → expand forward:
 *         num, num+1, num+2, ...
 *     - Count length of this sequence.
 * 3. Track maximum length.
 *
 * Justification:
 * - We only start counting from sequence "starts",
 *   avoiding repeated work → ensures O(N).
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * Why O(N)?
 * - Each number is processed at most once in sequence expansion.
 *
 * Edge Cases:
 * - Empty array → return 0
 * - Duplicates → handled automatically by set
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Key trick:
 *     Only start counting when (num-1) is NOT present
 *
 * - This ensures:
 *     ✔ Each sequence counted once
 *     ✔ No redundant traversals
 *
 * - Think:
 *     "Find sequence starts, not every element"
 *
 * - Example:
 *     [1,2,3,4]
 *     Only start from 1 (since 0 not present)
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Store all elements for O(1) lookup
        unordered_set<int> s(nums.begin(), nums.end());

        int longestLen = 0;

        for (int num : s) {

            // Check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {

                int currentNum = num;
                int currentLen = 1;

                // Expand forward
                while (s.count(currentNum + 1)) {
                    currentNum++;
                    currentLen++;
                }

                // Update maximum length
                longestLen = max(longestLen, currentLen);
            }
        }

        return longestLen;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Set + sequence expansion"
- Key idea:
    ✔ Only start from sequence beginnings

- Common mistake:
    ❌ Starting from every element → O(N²)
    ✔ Check (num-1) NOT present → ensures O(N)

- Mental model:
    "Expand only from valid starting points"

----------------------------------------------------------------------------
*/