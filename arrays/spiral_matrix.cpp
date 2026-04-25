/*
 * Problem: Spiral Matrix
 * Link: https://leetcode.com/problems/spiral-matrix/
 *
 * Definition:
 * - Given an m x n matrix,
 *   return all elements in spiral order.
 *
 * Spiral order means:
 * → left to right
 * → top to bottom
 * → right to left
 * → bottom to top
 * and repeat inward layer by layer
 *
 * Example:
 *
 * Input:
 * [
 *  [1,2,3],
 *  [4,5,6],
 *  [7,8,9]
 * ]
 *
 * Output:
 * [1,2,3,6,9,8,7,4,5]
 *
 * ----------------------------------------------------------------------------
 * Approach: Boundary Traversal
 *
 * We maintain 4 boundaries:
 *
 * top    → first unvisited row
 * bottom → last unvisited row
 * left   → first unvisited column
 * right  → last unvisited column
 *
 * At every step:
 *
 * 1. Traverse left → right (top row)
 * 2. Traverse top → bottom (right column)
 * 3. Traverse right → left (bottom row)
 * 4. Traverse bottom → top (left column)
 *
 * After each traversal,
 * move the respective boundary inward.
 *
 * Continue until boundaries cross.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(m × n)
 * Space Complexity: O(1)
 * (excluding output vector)
 *
 * Every element is visited exactly once.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - single row
 * - single column
 * - rectangular matrix
 * - odd dimensions
 *
 * Boundary checks are very important.
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Peeling the matrix like an onion"
 *
 * Outer layer first,
 * then move inward.
 *
 * This is a classic:
 *     ✔ Matrix Traversal
 *     ✔ Boundary Simulation
 *     ✔ Layer-by-layer processing
 *
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        // Boundaries of current layer
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;

        vector<int> spiral;

        while (left <= right && top <= bottom) {

            // ------------------------------------------------
            // Step 1: Left → Right
            // Traverse top row
            // ------------------------------------------------
            if (left <= right) {
                for (int i = left; i <= right; i++) {
                    spiral.push_back(matrix[top][i]);
                }
            } else {
                return spiral;                                  // No more columns to traverse
            }

            top++;              // Move top boundary down

            // ------------------------------------------------
            // Step 2: Top → Bottom
            // Traverse right column
            // ------------------------------------------------
            if (top <= bottom) {
                for (int i = top; i <= bottom; i++) {
                    spiral.push_back(matrix[i][right]);
                }
            } else {
                return spiral;                                  // No more rows to traverse
            }

            right--;            // Move right boundary left

            // ------------------------------------------------
            // Step 3: Right → Left
            // Traverse bottom row
            // ------------------------------------------------
            if (left <= right) {
                for (int i = right; i >= left; i--) {
                    spiral.push_back(matrix[bottom][i]);
                }
            } else {
                return spiral;                                  // No more columns to traverse
            }

            bottom--;           // Move bottom boundary up

            // ------------------------------------------------
            // Step 4: Bottom → Top
            // Traverse left column
            // ------------------------------------------------
            if (top <= bottom) {
                for (int i = bottom; i >= top; i--) {
                    spiral.push_back(matrix[i][left]);
                }
            } else {
                return spiral;                                  // No more rows to traverse
            }

            left++;             // Move left boundary right
        }

        return spiral;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Matrix Boundary Traversal

Core Variables:
    top
    bottom
    left
    right

Traversal Order:
    →
    ↓
    ←
    ↑

Then shrink boundaries

Most Important Part:
    Boundary checks after every traversal

Why?
    To avoid duplicate traversal
    especially in:
        single row
        single column cases

Common Mistakes:
    ❌ Missing boundary checks
    ❌ Wrong boundary updates
    ❌ Duplicate elements added

Interview Line:
    "Use 4 boundaries and peel the matrix layer by layer."

Mental Shortcut:
    Traverse → Shrink → Repeat

----------------------------------------------------------------------------
*/