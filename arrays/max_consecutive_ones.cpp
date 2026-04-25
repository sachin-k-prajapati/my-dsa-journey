/*
 * Problem: Max Consecutive Ones
 * Link: https://leetcode.com/problems/max-consecutive-ones/
 *
 * Definition:
 * - Given a binary array nums (only 0s and 1s),
 *   return the maximum number of consecutive 1's.
 *
 * Example:
 * Input:  [1,1,0,1,1,1]
 * Output: 3
 *
 * Explanation:
 * - First streak → 2 ones
 * - Second streak → 3 ones
 * - Maximum = 3
 *
 * ----------------------------------------------------------------------------
 * Approach: Linear Traversal + Running Count
 *
 * Idea:
 * - Keep counting consecutive 1s
 * - Whenever 0 appears:
 *      update answer
 *      reset count
 *
 * Steps:
 *
 * 1. Traverse the array
 * 2. If nums[i] == 1:
 *      increase current count
 *
 * 3. If nums[i] == 0:
 *      compare with maxCount
 *      reset count = 0
 *
 * 4. Final check after loop
 *    (important if array ends with 1s)
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Very common basic array pattern.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - all 1s
 * - all 0s
 * - single element
 * - longest streak at the end
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Track streak length"
 *
 * Whenever streak breaks:
 * save best answer and restart.
 *
 * Similar to:
 *     longest substring streak problems
 *
 * Pattern:
 *     ✔ Running Count
 *     ✔ Single Pass Traversal
 *     ✔ Streak Tracking
 *
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;      // current streak of 1s
        int maxCount = 0;   // best streak found so far

        for (int i = 0; i < nums.size(); i++) {

            // If current element is 1,
            // continue the streak
            if (nums[i] == 1) {
                count++;
            }
            else {
                // Streak breaks here
                maxCount = max(maxCount, count);
                count = 0;
            }
        }

        // Final update for case:
        // array ends with 1s
        maxCount = max(maxCount, count);

        return maxCount;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Running Count + Streak Tracking

Core Idea:
    Count consecutive 1s until 0 breaks the streak

Then:
    Compare and reset

Very Important:
    Final max() after loop

Why?
    Because longest streak may end at last index

Common Mistakes:
    ❌ Forgetting final update
    ❌ Resetting incorrectly
    ❌ Using unnecessary extra variables

Interview Line:
    "This is a simple streak-counting problem using O(1) space."

Mental Shortcut:
    Count → Break → Compare → Reset

----------------------------------------------------------------------------
*/