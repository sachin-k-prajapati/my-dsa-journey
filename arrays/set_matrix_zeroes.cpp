/*
 * Problem: Set Matrix Zeroes
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
 *
 * Definition:
 * - Given an m x n matrix, if any cell is 0,
 *   set its entire row and column to 0.
 * - Must be done **in-place** with **O(1) extra space**.
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Use first row and first column as markers instead of extra arrays.
 *
 * Steps:
 * 1. Check if first row or first column initially contains any zero.
 *    → Store in two flags: row, col
 *
 * 2. Traverse rest of matrix:
 *    - If matrix[i][j] == 0:
 *        mark:
 *            matrix[i][0] = 0
 *            matrix[0][j] = 0
 *
 * 3. Traverse again (excluding first row/col):
 *    - If row marker OR column marker is 0 → set cell to 0
 *
 * 4. Finally:
 *    - If first column had zero → set entire column to 0
 *    - If first row had zero → set entire row to 0
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(m * n)
 * - Space Complexity: O(1) (no extra arrays used)
 *
 * Why flags needed?
 * - First row/column are used as markers → we might overwrite original info
 * - So we separately store whether they originally had zero
 *
 * Edge Cases:
 * - Matrix with single row/column
 * - Entire matrix is zero
 * - Zero in first row or first column
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Instead of storing extra row/col arrays,
 *   we "reuse" the matrix itself.
 *
 * - First row → stores which columns should be zero
 * - First column → stores which rows should be zero
 *
 * - Flags (row, col) protect original state of first row/column
 *
 * - This is a classic:
 *     ✔ "In-place marking technique"
 *     ✔ Memory optimization trick
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col = false; // flag for first column
        bool row = false; // flag for first row

        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Check if first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col = true;
        }

        // Step 1: Check if first row has any zero
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) row = true;
        }

        // Step 2: Use first row & column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // mark column
                    matrix[i][0] = 0; // mark row
                }
            }
        }

        // Step 3: Update matrix using markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Update first column if needed
        if (col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        // Step 4: Update first row if needed
        if (row) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Use matrix itself as storage"
- Classic optimization:
    ✔ Instead of extra arrays → reuse first row & column

- Important:
    ❗ First row & column need special handling → use flags

- Common mistakes:
    ❌ Overwriting markers too early
    ❌ Forgetting to handle first row/column separately

- Mental model:
    "Mark first, then apply changes"

----------------------------------------------------------------------------
*/