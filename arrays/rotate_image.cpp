/*
 * Problem: Rotate Image
 * Link: https://leetcode.com/problems/rotate-image/
 *
 * Definition:
 * - Given an n x n matrix, rotate it by 90 degrees clockwise.
 *
 * - Must be done in-place
 *   → No extra 2D matrix allowed
 *
 * Example:
 * Input:
 * [
 *  [1,2,3],
 *  [4,5,6],
 *  [7,8,9]
 * ]
 *
 * Output:
 * [
 *  [7,4,1],
 *  [8,5,2],
 *  [9,6,3]
 * ]
 *
 * ----------------------------------------------------------------------------
 * Approach: Transpose + Reverse
 *
 * This is the most important trick.
 *
 * Step 1: Transpose the matrix
 * - Convert rows into columns
 *
 * Example:
 * [
 *  [1,2,3]
 *  [4,5,6]
 *  [7,8,9]
 * ]
 *
 * becomes
 *
 * [
 *  [1,4,7]
 *  [2,5,8]
 *  [3,6,9]
 * ]
 *
 * Step 2: Reverse every row
 *
 * [
 *  [7,4,1]
 *  [8,5,2]
 *  [9,6,3]
 * ]
 *
 * Final answer = 90° clockwise rotation
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N²)
 * Space Complexity: O(1)
 *
 * Since operation is in-place → optimal solution
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - 1 x 1 matrix
 * - 2 x 2 matrix
 * - negative values
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Clockwise rotation"
 *
 * Instead of manually rotating layer by layer,
 * use mathematical transformation:
 *
 *     Transpose
 *     +
 *     Reverse rows
 *
 * This is much cleaner and interview-preferred.
 *
 * Pattern:
 *     ✔ Matrix Transformation
 *     ✔ In-place Rotation
 *     ✔ Transpose Trick
 *
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // ------------------------------------------------
        // Step 1: Transpose the matrix
        //
        // matrix[i][j] becomes matrix[j][i]
        //
        // We start j from i to avoid double swapping
        // and avoid diagonal self-unnecessary work
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // ------------------------------------------------
        // Step 2: Reverse every row
        //
        // This completes 90 degree clockwise rotation
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Matrix Transformation

Most Important Trick:
    Transpose + Reverse

Clockwise Rotation:
    Transpose
    +
    Reverse each row

Anti-clockwise Rotation:
    Transpose
    +
    Reverse each column

Why j starts from i?
    To avoid:
        double swap
        unnecessary repeated work

Common Mistakes:
    ❌ Using extra matrix
    ❌ Reversing columns instead of rows
    ❌ Wrong transpose loop boundaries

Interview Line:
    "The optimal in-place solution uses transpose followed by row reversal."

Mental Shortcut:
    Transpose → Reverse Rows

----------------------------------------------------------------------------
*/