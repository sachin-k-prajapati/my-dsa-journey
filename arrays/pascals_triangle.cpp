/*
 * Problem: Pascal's Triangle
 * Link: https://leetcode.com/problems/pascals-triangle/
 *
 * Definition:
 * - Given numRows, generate the first numRows of Pascal’s Triangle.
 * - Each number = sum of two numbers directly above it.
 *
 * Example:
 * Input: numRows = 5
 * Output:
 * [
 *  [1],
 *  [1,1],
 *  [1,2,1],
 *  [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Start with first row: [1]
 * - For each next row:
 *     - First and last element are always 1
 *     - Middle elements:
 *         row[j] = previous_row[j] + previous_row[j+1]
 *
 * - Build row by row using previous row
 *
 * Justification:
 * - Pascal triangle follows a direct recurrence relation
 * - Each row depends only on previous row → perfect iterative build
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(numRows²)
 * - Space Complexity: O(numRows²) (storing all rows)
 *
 * Edge Cases:
 * - numRows = 1 → [[1]]
 * - numRows = 2 → [[1], [1,1]]
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of triangle growth:
 *     each new row = "expand previous row"
 *
 * - Pattern:
 *     edges → always 1
 *     middle → sum of two parents
 *
 * - You don’t need combinations formula (nCr),
 *   just build using previous row → more efficient and intuitive
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;

        // First row
        pascal.push_back({1});

        if (numRows == 1) return pascal;

        // Build remaining rows
        for (int i = 0; i < numRows - 1; i++) {
            vector<int> row;

            // First element always 1
            row.push_back(1);

            // Middle elements
            for (int j = 0; j < i; j++) {
                int num = pascal[i][j] + pascal[i][j + 1];
                row.push_back(num);
            }

            // Last element always 1
            row.push_back(1);

            pascal.push_back(row);
        }

        return pascal;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Build from previous row"
- Always:
    ✔ First and last element = 1
    ✔ Middle = sum of two above

- Common mistake:
    ❌ Trying to compute using factorial (nCr)
    ✔ Iterative build is simpler and avoids overflow

- Mental model:
    "Each row grows from previous like sliding window sum"

----------------------------------------------------------------------------
*/