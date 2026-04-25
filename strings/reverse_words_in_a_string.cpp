/*
 * Problem: Reverse Words in a String
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Definition:
 * - Given a string s, reverse the order of words.
 *
 * Rules:
 * - Remove leading spaces
 * - Remove trailing spaces
 * - Remove multiple spaces between words
 * - Final string should contain only single spaces
 *
 * Example:
 * Input:  "  hello world  "
 * Output: "world hello"
 *
 * ----------------------------------------------------------------------------
 * Approach: Word Extraction + Front Insertion
 *
 * Idea:
 * - Traverse the string and extract one word at a time
 * - Whenever a space (or end of string) is found:
 *      → add the current word at the FRONT of answer
 *
 * This automatically reverses word order.
 *
 * Steps:
 *
 * 1. Maintain:
 *      word → current word being formed
 *      str  → final reversed string
 *
 * 2. Traverse string:
 *      if character is not space:
 *          keep building word
 *
 * 3. If space or end reached:
 *      if word exists:
 *          prepend word to result
 *          clear word
 *
 * 4. Remove last extra space
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * (practically more due to front string insertion,
 * but accepted and clean for understanding)
 *
 * Space Complexity: O(N)
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - leading spaces
 * - trailing spaces
 * - multiple spaces between words
 * - single word
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * Instead of reversing whole string first,
 * directly place every word at the front.
 *
 * Example:
 *
 * "the sky is blue"
 *
 * Process:
 * "the"
 * "sky the"
 * "is sky the"
 * "blue is sky the"
 *
 * Final answer done directly.
 *
 * Pattern:
 *     ✔ String Parsing
 *     ✔ Word Extraction
 *     ✔ Reverse Construction
 *
 */

#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        string str;   // final answer
        string word;  // current word

        // Traverse including one extra step
        // to process last word
        for (int i = 0; i <= s.size(); i++) {

            // Build current word
            if (s[i] != ' ' && s[i] != '\0') {
                word += s[i];
            }

            else {
                // If valid word found,
                // place it at front
                if (word.size()) {
                    str = word + " " + str;
                }

                // Clear for next word
                word.clear();
            }
        }

        // Remove last extra trailing space
        str.pop_back();

        return str;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    String Parsing + Word Reversal

Core Idea:
    Extract word
    → insert at front

This automatically reverses order

Why word.size() check?
    To ignore multiple spaces

Why loop till <= size() ?
    To process last word also

Common Mistakes:
    ❌ Forgetting last word
    ❌ Extra spaces in output
    ❌ Not handling leading/trailing spaces

Interview Line:
    "Parse words and prepend each word to build reversed result."

Mental Shortcut:
    Extract → Prepend → Clear

----------------------------------------------------------------------------
*/