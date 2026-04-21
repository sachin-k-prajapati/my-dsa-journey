/*
 * Problem: Two Furthest Houses With Different Colors
 * Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 *
 * Definition:
 * - Given an array colors where colors[i] is the color of the i-th house,
 *   find the maximum distance |i - j| such that colors[i] != colors[j].
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Observe:
 *     - Maximum possible distance is between first and last house → (n-1)
 *     - If colors[0] != colors[n-1], answer is directly n-1.
 *
 * - Otherwise:
 *     - Fix start (colors[0]) and search from right side for first different color.
 *     - Fix end (colors[n-1]) and search from left side for first different color.
 *     - Take maximum of both distances.
 *
 * Justification:
 * - Maximum distance always involves either:
 *     1. First house with some different color on right
 *     2. Last house with some different color on left
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 * - Early exit if first and last differ → best case O(1)
 *
 * Edge Cases:
 * - Only two elements → always 1
 * - All same except one → handled via scanning
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - To maximize distance, always try to use boundary elements.
 * - If both ends are same, we "shrink inward" until we find mismatch.
 *
 * - Instead of checking all pairs (O(N²)),
 *   we exploit structure:
 *     → Best answer must involve one of the ends.
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int start = colors[0];
        int end = colors[n - 1];
        
        // Best case: ends are different → maximum distance
        if (start != end) return n - 1;
        
        int i = 1;
        int j = n - 2;

        int maxDis = 0;

        // Flags to stop early once both directions are resolved
        bool f1 = false;
        bool f2 = false;

        while (i <= j) {

            // Check from left side against end
            if (end != colors[i]) {
                maxDis = max(maxDis, n - i - 1);
                f1 = true;
            }

            // Check from right side against start
            if (start != colors[j]) {
                maxDis = max(maxDis, j);
                f2 = true;
            }

            // If both found, no need to continue
            if (f1 && f2) break;

            i++;
            j--;
        }

        return maxDis;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Use boundaries to maximize distance"
- Key insight:
    ✔ Max distance will always involve either index 0 or index n-1

- Avoid brute force:
    ❌ O(N²) checking all pairs
    ✔ Instead scan from edges → O(N)

- Mental shortcut:
    Compare:
        (last index - first different from start)
        (first index - last different from end)

----------------------------------------------------------------------------
*/