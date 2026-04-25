/*
 * Problem: Largest Odd Number in String
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 *
 * Definition:
 * - Given a numeric string num,
 *   return the largest-valued odd integer as a substring.
 *
 * - If no odd number exists, return "".
 *
 * Important:
 * - Substring must be contiguous
 * - We want the largest-valued odd number
 *
 * Example:
 * Input:  "35427"
 * Output: "35427"
 *
 * Input:  "52"
 * Output: "5"
 *
 * ----------------------------------------------------------------------------
 * Approach: Traverse from Right to Left
 *
 * Key Observation:
 * - A number is odd only if its LAST digit is odd
 *
 * So:
 * - To get the largest odd substring,
 *   we should keep the longest possible prefix
 *
 * That means:
 * - Find the rightmost odd digit
 * - Return substring from index 0 to that position
 *
 * Why?
 * - Any substring ending earlier would be smaller
 * - Prefix till rightmost odd digit gives maximum value
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * (excluding returned substring)
 *
 * Very clean greedy observation problem.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - all even digits → return ""
 * - already odd → return whole string
 * - single digit
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Largest odd number must end at an odd digit"
 *
 * So instead of checking all substrings:
 *
 * Just ask:
 * "Where is the last odd digit?"
 *
 * Everything before it should stay
 * to maximize value.
 *
 * Pattern:
 *     ✔ String Traversal
 *     ✔ Greedy Observation
 *     ✔ Prefix Selection
 *
 */

#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        int len = num.size();

        // Traverse from right to left
        for (int i = len - 1; i >= 0; i--) {

            // Odd digit check
            // ASCII odd digits also behave correctly here
            if ((int)num[i] % 2 != 0) {

                // Return largest prefix ending here
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    String Traversal + Greedy

Most Important Observation:
    Odd number ⇒ last digit must be odd

Core Trick:
    Find rightmost odd digit

Then:
    return prefix till that index

Why prefix?
    Because longer prefix = larger value

Common Mistakes:
    ❌ Checking all substrings
    ❌ Converting whole string to integer
    ❌ Ignoring simple odd-last-digit rule

Interview Line:
    "The largest odd substring is the longest prefix ending at the last odd digit."

Mental Shortcut:
    Last Odd Digit → Return Prefix

----------------------------------------------------------------------------
*/