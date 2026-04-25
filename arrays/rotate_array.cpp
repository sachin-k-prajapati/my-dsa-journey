/*
 * Problem: Rotate Array
 * Link: https://leetcode.com/problems/rotate-array/
 *
 * Definition:
 * - Given an integer array nums, rotate the array to the right by k steps.
 *
 * Example:
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 *
 * Meaning:
 * - Every element shifts right by k positions
 * - Elements going out from right come back to front
 *
 * ----------------------------------------------------------------------------
 * Approach: Reverse Technique (Optimal In-place)
 *
 * Instead of shifting one by one:
 *
 * Step 1:
 * - Reverse the entire array
 *
 * Step 2:
 * - Reverse first k elements
 *
 * Step 3:
 * - Reverse remaining (n-k) elements
 *
 * Why this works:
 *
 * Example:
 * nums = [1,2,3,4,5,6,7], k = 3
 *
 * Reverse whole:
 * [7,6,5,4,3,2,1]
 *
 * Reverse first k:
 * [5,6,7,4,3,2,1]
 *
 * Reverse remaining:
 * [5,6,7,1,2,3,4]
 *
 * Final answer achieved.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * - First reduce:
 *      k = k % n
 *   because rotating more than n times repeats pattern
 *
 * - This is the most preferred interview solution
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - k > n
 * - k == 0
 * - n == 1
 * - negative values inside array (doesn't matter)
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Bring last k elements to front"
 *
 * Instead of physically shifting:
 * use reverse operations to reposition efficiently.
 *
 * This is a classic:
 *     ✔ Array manipulation
 *     ✔ Reverse trick
 *     ✔ In-place optimization
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Important:
        // If k > n, reduce unnecessary rotations
        if (n < k) {
            k = k % n;
        }

        // ------------------------------------------------
        // Step 1: Reverse complete array
        // ------------------------------------------------
        int s = 0, e = n - 1;

        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }

        // ------------------------------------------------
        // Step 2: Reverse first k elements
        // ------------------------------------------------
        s = 0;
        e = k - 1;

        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }

        // ------------------------------------------------
        // Step 3: Reverse remaining elements
        // ------------------------------------------------
        s = k;
        e = n - 1;

        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Reverse Technique + In-place Array Rotation

Most Important Formula:
    k = k % n

Core Trick:
    Reverse Whole
    → Reverse First k
    → Reverse Remaining

Why not shift one by one?
    Because that becomes O(N * K)

Why this is better?
    Because only O(N)

Common Mistakes:
    ❌ Forgetting k % n
    ❌ Wrong reverse boundaries
    ❌ Confusing left vs right rotation

Interview Line:
    "This is the optimal O(1) space solution using reverse method."

Mental Shortcut:
    Reverse → Fix → Fix

----------------------------------------------------------------------------
*/