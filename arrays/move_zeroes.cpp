/*
 * Problem: Move Zeroes
 * Link: https://leetcode.com/problems/move-zeroes/
 *
 * Definition:
 * - Move all 0's to the end of the array
 * - Maintain relative order of non-zero elements
 * - Must be done in-place (no extra array)
 *
 * Example:
 * Input:  [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * ----------------------------------------------------------------------------
 * Approach: Two Pointer Compression
 *
 * Idea:
 * - Keep one pointer (ptr) that tells where the next non-zero
 *   element should be placed.
 *
 * Steps:
 *
 * 1. Traverse the array
 * 2. If current element is non-zero:
 *      place it at nums[ptr]
 *      increment ptr
 *
 * 3. After all non-zero elements are placed,
 *    fill remaining positions with 0
 *
 * Why this works:
 * - Non-zero elements stay in original order
 * - All zeros automatically move to the end
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * This is the optimal interview solution.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - all zeros
 * - no zeros
 * - single element
 * - zeros already at the end
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Compress all useful elements to the front"
 *
 * Then:
 * "Whatever space remains → fill with zero"
 *
 * This is similar to:
 *     Remove Duplicates from Sorted Array
 *
 * Pattern:
 *     ✔ Two Pointer
 *     ✔ In-place overwrite
 *     ✔ Stable ordering preserved
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // ptr = next position to place non-zero element
        int ptr = 0;

        // --------------------------------------------
        // Step 1: Move all non-zero elements forward
        // --------------------------------------------
        for (int i = 0; i < n; i++) {

            if (nums[i] != 0) {
                nums[ptr++] = nums[i];
            }
        }

        // --------------------------------------------
        // Step 2: Fill remaining positions with zero
        // --------------------------------------------
        while (ptr < n) {
            nums[ptr++] = 0;
        }
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Two Pointer + In-place Compression

Core Idea:
    Keep all non-zero elements in front

Then:
    Fill rest with zero

Why better than swapping repeatedly?
    Because fewer unnecessary operations

Common Mistakes:
    ❌ Using extra array
    ❌ Breaking order of non-zero elements
    ❌ Forgetting second loop for zero fill

Interview Line:
    "This is an in-place stable compression approach."

Mental Shortcut:
    Compress → Fill

----------------------------------------------------------------------------
*/