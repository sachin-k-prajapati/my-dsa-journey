/*
 * Problem: Merge Sorted Array
 * Link: https://leetcode.com/problems/merge-sorted-array/
 *
 * Definition:
 * - We are given two sorted arrays:
 *      nums1 → size = m + n
 *      nums2 → size = n
 *
 * - First m elements of nums1 are valid elements,
 *   last n elements are just extra space (0 placeholders).
 *
 * - Merge nums2 into nums1 such that nums1 becomes
 *   one fully sorted array.
 *
 * - Final answer must be stored inside nums1 itself.
 *
 * ----------------------------------------------------------------------------
 * Approach 1: Extra Array (Simple Merge)
 *
 * - This is the classic merge process used in Merge Sort.
 * - Use two pointers:
 *      i → nums1 valid part
 *      j → nums2
 *
 * - Compare both and store smaller element in a temporary array.
 * - After merging, copy temp array back into nums1.
 *
 * Why?
 * - Very easy to understand and safe.
 * - But uses extra O(m+n) space.
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(m + n)
 *
 * ----------------------------------------------------------------------------
 * Approach 2: In-place Optimal (Backward Two Pointers)
 *
 * - Since nums1 already has enough extra space at the end,
 *   we should fill it from the BACK.
 *
 * Why from back?
 * - If we start from front → original nums1 values get overwritten.
 * - From back → safe because empty spaces are already there.
 *
 * Steps:
 * - ptr1 = last valid element of nums1
 * - ptr2 = last element of nums2
 * - currPos = last index of nums1
 *
 * Compare:
 * - Bigger element goes at currPos
 * - Move pointers backward
 *
 * Remaining nums2 elements (if any) are copied.
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * - Approach 2 is preferred in interviews.
 * - Backward filling is the main trick.
 * - If nums2 finishes first → done.
 * - If nums1 finishes first → copy remaining nums2.
 *
 * Edge Cases:
 * - m = 0
 * - n = 0
 * - duplicate values
 * - already sorted arrays
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "I already have empty space at the back,
 * so why create another array?"
 *
 * Use that free space smartly.
 *
 * This is a classic:
 *     ✔ Two Pointer
 *     ✔ In-place merging
 *     ✔ Reverse traversal trick
 *
 */


#include <vector>
using namespace std;


/* =========================================================
   Solution 1: Extra Array Method
   ========================================================= */

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Temporary merged array
        vector<int> s(m + n, 0);

        int i = 0, j = 0;

        // Merge both arrays like merge sort
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                s[i + j] = nums1[i];
                i++;
            } else {
                s[i + j] = nums2[j];
                j++;
            }
        }

        // Remaining nums1 elements
        while (i < m) {
            s[i + j] = nums1[i];
            i++;
        }

        // Remaining nums2 elements
        while (j < n) {
            s[i + j] = nums2[j];
            j++;
        }

        // Copy back to nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = s[k];
        }
    }
};


/* =========================================================
   Solution 2: Optimal In-place Method
   ========================================================= */

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Last valid element of nums1
        int ptr1 = m - 1;

        // Last element of nums2
        int ptr2 = n - 1;

        // Last index of nums1 (total space)
        int currPos = m + n - 1;

        // Fill nums1 from back
        while (ptr1 >= 0 && ptr2 >= 0) {

            if (nums1[ptr1] >= nums2[ptr2]) {
                nums1[currPos] = nums1[ptr1];
                ptr1--;
                currPos--;
            } else {
                nums1[currPos] = nums2[ptr2];
                ptr2--;
                currPos--;
            }
        }

        // If nums2 still has elements left
        while (ptr2 >= 0) {
            nums1[currPos] = nums2[ptr2];
            currPos--;
            ptr2--;
        }

        // No need for nums1 leftovers:
        // they are already in correct place
    }
};


/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Two Pointer + In-place Merge

Most Important Trick:
    Fill from BACK

Why?
    Because front filling destroys useful nums1 values

Common Mistakes:
    ❌ Filling from front
    ❌ Forgetting nums2 leftovers
    ❌ Using extra array when interviewer asks O(1) space

Interview Line:
    "Since nums1 already has enough extra space,
     we can optimize space by merging from the end."

Mental Shortcut:
    Merge Sort logic + reverse direction

----------------------------------------------------------------------------
*/