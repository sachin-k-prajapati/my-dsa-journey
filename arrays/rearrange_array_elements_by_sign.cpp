/*
 * Problem: Rearrange Array Elements by Sign
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 *
 * Definition:
 * - Given an array with equal number of positive and negative integers,
 *   rearrange it such that:
 *     1. Alternate signs (pos, neg, pos, neg...)
 *     2. Order of positives and negatives is preserved (stable)
 *     3. First element must be positive
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Create a new array of same size.
 * - Maintain two pointers:
 *     - pos → for placing positive numbers (even indices: 0, 2, 4...)
 *     - neg → for placing negative numbers (odd indices: 1, 3, 5...)
 *
 * - Traverse original array:
 *     - If element > 0 → place at pos index and move pos += 2
 *     - Else → place at neg index and move neg += 2
 *
 * Justification:
 * - Since counts of positive and negative are equal,
 *   we can safely fill alternate positions without overflow.
 * - Stability is maintained because we process array in order.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(N) (extra array used)
 * - Stable ordering is preserved automatically.
 * - No need to sort or use complex structures.
 *
 * Edge Cases:
 * - Minimum size (n = 2)
 * - Already alternating → still processed correctly
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Instead of separating positives & negatives and merging,
 *   directly "place" elements at correct positions.
 *
 * - Think of:
 *     even indices → reserved for positives
 *     odd indices  → reserved for negatives
 *
 * - This guarantees:
 *     ✔ Alternating pattern
 *     ✔ Original order preserved
 *     ✔ Clean O(N) solution
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        // Result array
        vector<int> v(n);

        // pos → index for positives (even positions)
        // neg → index for negatives (odd positions)
        int pos = 0;
        int neg = 1;

        for (int i = 0; i < n; i++) {

            // If positive → place at even index
            if (nums[i] > 0) {
                v[pos] = nums[i];
                pos += 2;
            }
            // If negative → place at odd index
            else {
                v[neg] = nums[i];
                neg += 2;
            }
        }

        return v;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Index Placement Technique"
- Common trick:
    ✔ Even index → one type
    ✔ Odd index  → another type

- Why this works:
    Because count(pos) == count(neg)

- Alternative approach (less optimal mentally):
    1. Store positives and negatives separately
    2. Merge them → alternating
    (but uses more steps)

- This approach is cleaner and direct.

----------------------------------------------------------------------------
*/