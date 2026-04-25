/*
 * Problem: Valid Anagram
 * Link: https://leetcode.com/problems/valid-anagram/
 *
 * Definition:
 * - Given two strings s and t,
 *   return true if t is an anagram of s.
 *
 * Anagram means:
 * - Both strings contain exactly the same characters
 * - Same frequency of each character
 * - Order does NOT matter
 *
 * Example:
 * s = "anagram"
 * t = "nagaram"
 *
 * → true
 *
 * Example:
 * s = "rat"
 * t = "car"
 *
 * → false
 *
 * ----------------------------------------------------------------------------
 * Approach: Frequency Counting using Array
 *
 * Since:
 * - strings contain only lowercase English letters
 *
 * We use:
 * vector<int> alpha(26)
 *
 * where:
 * alpha[i] = frequency of character ('a' + i)
 *
 * Steps:
 *
 * 1. Count all characters of t
 *      → increment frequency
 *
 * 2. Traverse s
 *      → decrement frequency
 *
 * 3. If finally all values become 0
 *      → both strings are anagrams
 *
 * Otherwise:
 *      → not an anagram
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Why O(1)?
 * Because array size is fixed = 26
 *
 * This is the optimal solution for lowercase letters.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - different lengths
 * - repeated characters
 * - completely different strings
 * - same strings
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Every character added must be removed"
 *
 * Example:
 *
 * t = "nagaram"
 * → count all chars
 *
 * s = "anagram"
 * → remove all chars
 *
 * Final:
 * all zero → valid anagram
 *
 * Pattern:
 *     ✔ Frequency Count
 *     ✔ Hashing
 *     ✔ Character Matching
 *
 * Follow-up (Unicode):
 * - For Unicode characters,
 *   use unordered_map<char, int>
 *   instead of fixed 26 array
 *
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();
        int m = t.size();

        // Frequency array for 26 lowercase letters
        vector<int> alpha(26, 0);

        // ------------------------------------------------
        // Count characters of string t
        // ------------------------------------------------
        for (int i = 0; i < m; i++) {
            alpha[t[i] - 'a']++;
        }

        // ------------------------------------------------
        // Remove characters of string s
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {
            alpha[s[i] - 'a']--;
        }

        // ------------------------------------------------
        // Final validation:
        // all frequencies must be zero
        // ------------------------------------------------
        for (int i = 0; i < 26; i++) {

            if (alpha[i] == 0) {
                continue;
            } 
            else {
                return false;
            }
        }

        return true;
    }
};


/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Frequency Count

Core Idea:
    Same characters + Same frequency

Best Tool:
    Fixed array of size 26

Why not sorting?
    Sorting → O(N log N)

This method:
    O(N)

Much better.

Most Important Thought:
    Add from one string
    Remove from another

Final check:
    everything must become zero

Common Mistakes:
    ❌ Forgetting length mismatch logic
    ❌ Using sorting unnecessarily
    ❌ Wrong character indexing

Interview Line:
    "Use frequency counting since only lowercase English letters exist."

Mental Shortcut:
    Count → Remove → Verify Zero

----------------------------------------------------------------------------
*/