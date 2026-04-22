/*
 * Problem: Next Permutation
 * Link: https://leetcode.com/problems/next-permutation/
 *
 * Definition:
 * - Rearrange the array into the next lexicographically greater permutation.
 * - If not possible (i.e., array is in descending order), rearrange to lowest (ascending).
 * - Must be done in-place with O(1) extra space.
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * Step-by-step logic:
 *
 * 1. Find the "breakpoint" (index):
 *    - Traverse from right → find first index i such that:
 *          nums[i] < nums[i+1]
 *    - This is where permutation can be increased.
 *
 * 2. If breakpoint exists:
 *    - Find smallest number > nums[index] from right side
 *    - Swap them
 *
 * 3. Reverse the suffix:
 *    - Reverse elements after index → make smallest possible order
 *
 * If no breakpoint:
 *    → Entire array is descending → reverse whole array
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 * - Uses:
 *     ✔ Reverse suffix trick
 *     ✔ Greedy + lexicographic ordering
 *
 * Edge Cases:
 * - Fully decreasing array → [3,2,1] → [1,2,3]
 * - Duplicate values → handled naturally
 * - Single element → unchanged
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of permutation as a number:
 *     You want the "next bigger number"
 *
 * - Rightmost part is the most flexible:
 *     → Try to increase from right side
 *
 * - Breakpoint = where increasing order breaks
 * - Swap = minimal increase
 * - Reverse suffix = smallest arrangement after that
 *
 * - This ensures:
 *     ✔ Next greater (not just greater)
 *     ✔ Lexicographically smallest possible next
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find breakpoint (first decreasing element from right)
        int index = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                index = i - 1;
                break;
            }
        }

        // Step 2: If breakpoint found, swap with next greater element from right
        if (index != -1) {
            int j = n - 1;
            while (j > index) {
                if (nums[j] > nums[index]) {
                    swap(nums[j], nums[index]);
                    break;
                }
                j--;
            }
        }

        // Step 3: Reverse the suffix to get smallest order
        reverse(nums.begin() + index + 1, nums.end());
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Lexicographical permutation + greedy"
- Always:
    1. Find break
    2. Swap
    3. Reverse

- Why reverse?
    Because right side is already in descending order → reversing makes it smallest

- Common mistake:
    ❌ Sorting suffix (works but slower)
    ✔ Reverse is enough

- Mental model:
    "Next greater number using same digits"

----------------------------------------------------------------------------
*/