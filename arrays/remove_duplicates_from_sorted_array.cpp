/*
 * Problem: Remove Duplicates from Sorted Array
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Definition:
 * - Given a sorted array nums, remove duplicates in-place such that
 *   each unique element appears only once.
 *
 * - Return k = number of unique elements.
 *
 * - First k positions of nums should contain unique sorted values.
 * - Elements after k are irrelevant.
 *
 * Example:
 * Input: [1,1,2]
 * Output: k = 2 → nums = [1,2,_]
 *
 * ----------------------------------------------------------------------------
 * Approach 1: Nested Loop + Manual Left Shift
 *
 * - Since array is sorted, duplicates will always be adjacent or ahead.
 *
 * Steps:
 * 1. For every element nums[i]
 * 2. Check all next elements nums[j]
 * 3. If duplicate found:
 *      - shift all elements left by 1
 *      - reduce length
 *      - stay on same j to check again
 *
 * Why?
 * - Straightforward brute-force thinking.
 * - Easy to understand during early DSA learning.
 *
 * Time Complexity: O(N^3) worst case
 * Space Complexity: O(1)
 *
 * ----------------------------------------------------------------------------
 * Approach 2: Single Forward Check + Shift
 *
 * - Since array is sorted, duplicates are consecutive.
 *
 * Steps:
 * 1. Compare nums[i] with nums[i+1]
 * 2. If same:
 *      - shift remaining array left by 1
 *      - reduce size
 *      - move i back to recheck
 *
 * Why better?
 * - No need inner j loop for searching
 * - Still uses shifting, but cleaner than approach 1
 *
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * - Sorted property is the main advantage
 * - Duplicates are always adjacent
 * - Resize at end only for local representation
 *
 * Edge Cases:
 * - all same elements
 * - no duplicates
 * - single element
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Since array is sorted:
 *
 *     duplicate ⇒ next to each other
 *
 * so instead of searching whole array,
 * just detect repetition and compress array.
 *
 * This is a classic:
 *     ✔ Array Compression
 *     ✔ In-place modification
 *     ✔ Two-pointer optimized version exists
 *
 * (Your current solutions are shift-based approaches)
 *
 */

#include <vector>
using namespace std;


/* =========================================================
   Solution 1: Nested Loop + Full Duplicate Search
   ========================================================= */

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int Len = nums.size();

        for (int i = 0; i < Len; i++) {

            // Check all next elements for duplicates
            for (int j = i + 1; j < Len; j++) {

                if (nums[i] == nums[j]) {

                    // Shift all elements left
                    for (int k = j; k < Len - 1; k++) {
                        nums[k] = nums[k + 1];
                    }

                    --Len;
                    --j; // stay here to check again
                }
            }
        }

        nums.resize(Len);
        return nums.size();
    }
};


/* =========================================================
   Solution 2: Adjacent Duplicate Check + Shift
   ========================================================= */

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {

            // Since sorted, just compare adjacent elements
            if (nums[i] == nums[i + 1]) {

                int k = i;

                // Shift remaining elements left
                while (k < n - 1) {
                    nums[k] = nums[k + 1];
                    k++;
                }

                n--;
                i--; // recheck same position
            }
        }

        nums.resize(n);
        return nums.size();
    }
};


/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Sorted Array + In-place Compression

Main Observation:
    Since sorted → duplicates stay together

Your Learning Progress:
    Solution 1 → brute force understanding
    Solution 2 → smarter using sorted property

Most Optimal Interview Version:
    Two Pointer Method (O(N))

But these solutions are important because:
they build the real intuition before optimization.

Common Mistakes:
    ❌ Forgetting i--
    ❌ Missing repeated duplicates
    ❌ Wrong resize handling

Mental Model:
    "Detect duplicate → compress array"

----------------------------------------------------------------------------
*/