/*
 * Problem: 3Sum
 * Link: https://leetcode.com/problems/3sum/
 *
 * Definition:
 * - Given an integer array nums,
 *   return all unique triplets:
 *
 *      [nums[i], nums[j], nums[k]]
 *
 * such that:
 *      i != j != k
 * and
 *      nums[i] + nums[j] + nums[k] == 0
 *
 * - Duplicate triplets are NOT allowed.
 *
 * Example:
 * Input:
 * [-1,0,1,2,-1,-4]
 *
 * Output:
 * [[-1,-1,2],[-1,0,1]]
 *
 * ----------------------------------------------------------------------------
 * Approach: Sorting + Two Pointers
 *
 * Brute Force:
 * - Try all triplets → O(N³)
 * Too slow.
 *
 * Better Idea:
 *
 * Step 1:
 * - Sort the array
 *
 * Step 2:
 * - Fix one element nums[i]
 *
 * Step 3:
 * - Use two pointers for remaining part:
 *      start = i + 1
 *      end   = n - 1
 *
 * Step 4:
 * - Check:
 *      nums[i] + nums[start] + nums[end]
 *
 * If sum == 0:
 * → valid triplet found
 *
 * If sum < 0:
 * → need bigger value → move start++
 *
 * If sum > 0:
 * → need smaller value → move end--
 *
 * Also:
 * - Skip duplicates for:
 *      i
 *      start
 *      end
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N²)
 * Space Complexity: O(1)
 * (excluding answer vector)
 *
 * Sorting is the key optimization.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - all zeros → [[0,0,0]]
 * - no valid triplet
 * - duplicate values
 * - negative-heavy arrays
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Fix one number, solve 2Sum for the rest"
 *
 * Since array is sorted:
 * Two-pointer works perfectly.
 *
 * Duplicate skipping is the most important part.
 *
 * This is a classic:
 *     ✔ Sorting
 *     ✔ Two Pointer
 *     ✔ Duplicate Handling
 *
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> Sum;

        // Step 2: Fix first element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int start = i + 1;
            int end = n - 1;

            // Step 3: Two pointer search
            while (start < end) {

                int Check = nums[i] + nums[start] + nums[end];

                if (Check == 0) {

                    // Valid triplet found
                    Sum.push_back({nums[i], nums[start], nums[end]});

                    // Skip duplicate start values
                    while (start < end && nums[start] == nums[start + 1]) {
                        start++;
                    }

                    // Skip duplicate end values
                    while (start < end && nums[end] == nums[end - 1]) {
                        end--;
                    }

                    start++;
                    end--;
                }

                else if (Check < 0) {
                    // Need bigger sum
                    start++;
                }

                else {
                    // Need smaller sum
                    end--;
                }
            }
        }

        return Sum;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Sorting + Two Pointer

Core Idea:
    Fix one element
    → solve 2Sum using two pointers

Most Important Part:
    Skip duplicates

Duplicate handling needed for:
    i
    start
    end

Why sort first?
    Because two-pointer only works on sorted arrays

Why not brute force?
    O(N³) too slow

This gives:
    O(N²) optimal accepted solution

Common Mistakes:
    ❌ Forgetting duplicate skipping
    ❌ Wrong pointer movement
    ❌ Using set unnecessarily

Interview Line:
    "Fix one element and reduce problem to 2Sum using two pointers."

Mental Shortcut:
    Fix One → Two Sum → Skip Duplicates

----------------------------------------------------------------------------
*/