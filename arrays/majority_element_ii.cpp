/*
 * Problem: Majority Element II
 * Link: https://leetcode.com/problems/majority-element-ii/
 *
 * Definition:
 * - Given an array of size n, return all elements that appear more than ⌊ n/3 ⌋ times.
 * - There can be at most 2 such elements.
 *
 * Example:
 * Input: [3,2,3]
 * Output: [3]
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Use extended Boyer-Moore Voting Algorithm.
 *
 * Steps:
 * 1. Maintain two candidates (candidate1, candidate2) and their counts.
 * 2. Traverse array:
 *     - If matches candidate → increment count
 *     - Else if count is 0 → assign new candidate
 *     - Else → decrement both counts
 *
 * 3. Second pass:
 *     - Verify if candidates actually appear more than n/3 times
 *
 * Justification:
 * - Since more than n/3 → at most 2 elements can satisfy this condition.
 * - Voting algorithm eliminates non-majority elements efficiently.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * Why 2 candidates?
 * - Because ⌊n/3⌋ → max 2 possible majority elements
 *
 * Edge Cases:
 * - n = 1 → single element is answer
 * - n = 2 → both can be answers
 * - No element > n/3 → return empty
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of it as "cancelling out" non-majority elements.
 *
 * - If an element appears more than n/3 times:
 *     → it cannot be completely cancelled out
 *
 * - Remaining candidates after first pass are potential answers,
 *   but need verification.
 *
 * - Pattern:
 *     ✔ Voting / elimination strategy
 *     ✔ Similar to majority element (n/2), but extended to 2 candidates
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int candidate1;
        int candidate2;

        int count1 = 0;
        int count2 = 0;

        // Phase 1: Find potential candidates
        for (int num : nums) {

            if (num == candidate1) {            // If matches candidate1 → increment count1
                count1++;
            }
            else if (num == candidate2) {       // If matches candidate2 → increment count2
                count2++;
            }
            else if (count1 == 0) {             // If count1 is 0 → assign new candidate1 and reset count1 to 1
                candidate1 = num;
                count1++;
            }
            else if (count2 == 0) {             // If count2 is 0 → assign new candidate2 and reset count2 to 1
                candidate2 = num;
                count2++;
            }
            else {                              // Else → decrement both counts because we found a different element that is not a candidate, so we can "cancel out" one occurrence of each candidate
                count1--;
                count2--;
            }
        }

        // Phase 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1) count1++;            // Count occurrences of candidate1
            if (num == candidate2) count2++;            // Count occurrences of candidate2
        }

        // Check if candidates appear more than n/3 times and add to answer
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Boyer-Moore Voting (Extended)"
- Key insight:
    ✔ Max 2 elements can appear more than n/3 times

- Always:
    1. Find candidates
    2. Verify them

- Common mistakes:
    ❌ Forgetting second pass (verification)
    ❌ Assuming candidates are always valid

- Mental model:
    "Eliminate groups of 3 different elements"

----------------------------------------------------------------------------
*/