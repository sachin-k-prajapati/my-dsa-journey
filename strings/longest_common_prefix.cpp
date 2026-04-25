/*
 * Problem: Longest Common Prefix
 * Link: https://leetcode.com/problems/longest-common-prefix/
 *
 * Definition:
 * - Given an array of strings,
 *   find the longest prefix common to all strings.
 *
 * - If no common prefix exists,
 *   return empty string ""
 *
 * Example:
 * Input:  ["flower","flow","flight"]
 * Output: "fl"
 *
 * Input:  ["dog","racecar","car"]
 * Output: ""
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * Compare every string with the first string
 *
 * Idea:
 * - Take first string as reference
 * - Compare character by character with every other string
 * - Find how many characters match from the beginning
 * - Final answer = minimum matched prefix among all strings
 *
 * Since prefix must be common in ALL strings,
 * we always keep the minimum prefix length.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N * M)
 * where:
 * N = number of strings
 * M = length of shortest comparison prefix
 *
 * Space Complexity: O(1)
 * (excluding returned string)
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - only one string
 * - empty string present
 * - no common prefix
 * - all strings same
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Prefix must start from index 0"
 *
 * So no need to check substrings inside.
 * Only compare from the beginning.
 *
 * Example:
 *
 * flower
 * flow
 * flight
 *
 * Matching:
 * f → yes
 * l → yes
 * o → no
 *
 * Answer = "fl"
 *
 * Pattern:
 *     ✔ String Comparison
 *     ✔ Prefix Matching
 *     ✔ Minimum Common Length
 *
 */

#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int totalStrings = strs.size();

        // Take first string as reference
        string first = strs[0];

        // Stores smallest matching prefix length
        int longestCommonPrefix = INT_MAX;

        // Compare first string with every other string
        for (int i = 1; i < totalStrings; i++) {

            string second = strs[i];

            int countOfIndex = 0;

            // Compare character by character
            for (int j = 0; j < first.size() && j < second.size(); j++) {

                if (first[j] == second[j]) {
                    countOfIndex++;
                }
                else {
                    break;
                }
            }

            // Keep minimum common prefix length
            longestCommonPrefix = min(longestCommonPrefix, countOfIndex);
        }

        // Return prefix from first string
        return first.substr(0, longestCommonPrefix);
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    String Comparison + Prefix Matching

Core Idea:
    Compare all strings with first string

Why first string?
    Because final answer must be a prefix of it

Main Logic:
    Count matching characters
    Keep minimum prefix length

Final Answer:
    first.substr(0, minimumLength)

Common Mistakes:
    ❌ Checking substrings instead of prefix only
    ❌ Forgetting empty string case
    ❌ Not taking minimum prefix length

Interview Line:
    "Use first string as reference and keep shrinking the valid prefix."

Mental Shortcut:
    Compare → Count → Min → Substr

----------------------------------------------------------------------------
*/