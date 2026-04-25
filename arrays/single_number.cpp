/*
 * Problem: Single Number
 * Link: https://leetcode.com/problems/single-number/
 *
 * Definition:
 * - Every element appears exactly twice except one element
 *   which appears only once.
 *
 * - Find that single unique element.
 *
 * Constraints:
 * - Must solve in O(N) time
 * - Must use O(1) extra space
 *
 * Example:
 * Input:  [4,1,2,1,2]
 * Output: 4
 *
 * ----------------------------------------------------------------------------
 * Approach: Bit Manipulation using XOR
 *
 * Key XOR Properties:
 *
 * 1. a ^ a = 0
 *    → same numbers cancel each other
 *
 * 2. a ^ 0 = a
 *    → zero does not affect result
 *
 * 3. XOR is commutative and associative
 *    → order does not matter
 *
 * So:
 * - XOR all elements together
 * - Every duplicate pair cancels out
 * - Only the single unique number remains
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * This is the optimal and expected interview solution.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - only one element
 * - negative numbers
 * - unique element at beginning/end
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Duplicate pairs destroy each other"
 *
 * Example:
 * [2,2,1]
 *
 * → 2 ^ 2 ^ 1
 * → 0 ^ 1
 * → 1
 *
 * Final answer = unique number
 *
 * Pattern:
 *     ✔ Bit Manipulation
 *     ✔ XOR Trick
 *     ✔ Constant Space Optimization
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Stores cumulative XOR result
        int num = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Duplicate numbers cancel each other
            num = num ^ nums[i];
        }

        // Remaining value = single number
        return num;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    XOR Trick

Most Important Formula:
    a ^ a = 0

Core Idea:
    Duplicate numbers cancel out automatically

Why not HashMap?
    Because question asks:
        O(N) time
        O(1) space

This is perfect for XOR.

Common Mistakes:
    ❌ Using sorting
    ❌ Using hashmap unnecessarily
    ❌ Forgetting XOR properties

Interview Line:
    "Using XOR eliminates duplicate pairs and leaves only the unique element."

Mental Shortcut:
    Pair cancels → single survives

----------------------------------------------------------------------------
*/