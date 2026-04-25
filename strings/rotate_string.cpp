/*
 * Problem: Rotate String
 * Link: https://leetcode.com/problems/rotate-string/
 *
 * Definition:
 * - Given two strings s and goal,
 *   return true if s can become goal after some number of shifts.
 *
 * Shift means:
 * - Move leftmost character to the rightmost position
 *
 * Example:
 * "abcde"
 * → "bcdea"
 * → "cdeab"
 *
 * Example:
 * Input:
 * s = "abcde"
 * goal = "cdeab"
 *
 * Output:
 * true
 *
 * ----------------------------------------------------------------------------
 * Approach 1: Manual Rotation Simulation
 *
 * Idea:
 * - Rotate the string one by one
 * - After every rotation, check if it becomes goal
 *
 * Steps:
 *
 * 1. If sizes differ → impossible
 * 2. Rotate string at most n times
 * 3. If any rotation matches → true
 * 4. Else → false
 *
 * This is intuitive and easy to understand.
 *
 * ----------------------------------------------------------------------------
 * Approach 2: Duplicate String Trick (Optimal)
 *
 * Key Observation:
 *
 * If goal is a rotation of s,
 * then goal must always exist inside:
 *
 *      s + s
 *
 * Example:
 *
 * s = "abcde"
 *
 * s + s = "abcdeabcde"
 *
 * goal = "cdeab"
 * exists inside duplicate string
 *
 * Therefore:
 * if goal is substring of (s + s)
 * → answer is true
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Approach 1:
 * Time: O(N²)
 * Space: O(1)
 *
 * Approach 2:
 * Time: O(N)
 * Space: O(N)
 *
 * Approach 2 is interview preferred.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - different lengths
 * - same string
 * - single character
 * - impossible rotation
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Rotation means:
 * prefix moves to suffix
 *
 * All possible rotations are already present inside:
 *
 *      s + s
 *
 * This is the beautiful trick.
 *
 * Pattern:
 *     ✔ String Rotation
 *     ✔ Simulation
 *     ✔ Concatenation Trick
 *
 */

#include <string>
using namespace std;

////////////////////////////////////////////////////////////
// Solution 1 : Manual Rotation Simulation
////////////////////////////////////////////////////////////

class Solution {
public:

    // Rotates string by one step
    // Example:
    // abcde -> eabcd
    string rotate(string &s) {
        char l = s[s.size() - 1];

        for (int i = s.size() - 1; i > 0; --i) {
            s[i] = s[i - 1];
        }

        s[0] = l;
        return s;
    }

    bool rotateString(string s, string goal) {

        // Different sizes -> impossible
        if (s.size() != goal.size()) return false;

        // Try all possible rotations
        for (int i = 0; i < s.size(); i++) {

            if (s == goal) return true;

            rotate(s);
        }

        return false;
    }
};

////////////////////////////////////////////////////////////
// Solution 2 : Duplicate String Trick (Optimal)
////////////////////////////////////////////////////////////

class Solution {
public:
    bool rotateString(string s, string goal) {

        // Length mismatch -> impossible
        if (s.length() != goal.length()) return false;

        // All rotations of s exist inside s+s
        string duplicate = s + s;

        return duplicate.find(goal) != string::npos;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    String Rotation + Substring Trick

Most Important Observation:
    If goal is rotation of s

Then:
    goal must exist inside

        s + s

Example:
    abcde + abcde
    = abcdeabcde

Contains:
    bcdea
    cdeab
    deabc
    etc.

Why?
    Because every cyclic rotation appears there

Approach Preference:
    Simulation → easy to understand
    Duplicate trick → optimal solution

Common Mistakes:
    ❌ Forgetting length check
    ❌ Confusing left rotation vs right rotation
    ❌ Using simulation when optimal expected

Interview Line:
    "All rotations of a string are present inside s + s."

Mental Shortcut:
    Rotation → Duplicate String Check

----------------------------------------------------------------------------
*/