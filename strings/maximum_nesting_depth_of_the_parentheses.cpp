/*
 * Problem: Maximum Nesting Depth of the Parentheses
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 *
 * Definition:
 * - Given a valid parentheses string (VPS),
 *   return the maximum nesting depth.
 *
 * Nesting depth means:
 * - How deeply parentheses are inside each other
 *
 * Example:
 * s = "(1+(2*3)+((8)/4))+1"
 *
 * Depth levels:
 * (
 *   (
 *     (
 *       8
 *     )
 *   )
 * )
 *
 * Maximum depth = 3
 *
 * ----------------------------------------------------------------------------
 * Approach: Running Depth Counter
 *
 * Since the string is already guaranteed valid,
 * we do NOT need stack validation.
 *
 * We only need:
 *
 * currDepth → current nesting level
 * maxDepth  → maximum seen so far
 *
 * Rules:
 *
 * If '(' found:
 *      currDepth++
 *
 * If ')' found:
 *      currDepth--
 *
 * After every step:
 *      update maxDepth
 *
 * Final answer:
 *      maximum currDepth reached
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Stack is unnecessary here.
 *
 * Simple counter is enough.
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - no nesting → "()"
 * - deep nesting → "((()))"
 * - mixed digits/operators
 * - multiple separate groups
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "(" means go one level deeper
 * ")" means come one level back
 *
 * Like:
 * climbing stairs and tracking
 * highest floor reached.
 *
 * Example:
 *
 * (()())
 *
 * depth:
 * 1 → 2 → 1 → 2 → 1 → 0
 *
 * Maximum = 2
 *
 * Pattern:
 *     ✔ String Traversal
 *     ✔ Counter Tracking
 *     ✔ Parentheses Depth
 *
 */

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {

        int n = s.length();

        // Stores final maximum nesting depth
        int maxDepth = 0;

        // Stores current active depth
        int currDepth = 0;

        // ------------------------------------------------
        // Traverse the string character by character
        // ------------------------------------------------
        for (char c : s) {

            // Opening bracket means
            // going one level deeper
            if (c == '(') {
                currDepth++;
            }

            // Closing bracket means
            // coming one level up
            else if (c == ')') {
                currDepth--;
            }

            // Update maximum depth reached so far
            maxDepth = max(maxDepth, currDepth);
        }

        return maxDepth;
    }
};


/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Parentheses + Counter Tracking

Core Idea:
    '(' → increase depth
    ')' → decrease depth

Final Answer:
    Maximum depth reached

Why no stack?
    Because input is guaranteed valid

So:
    simple counter is enough

This is cleaner and faster

Common Mistakes:
    ❌ Using unnecessary stack
    ❌ Updating max before increment
    ❌ Forgetting multiple separate groups

Interview Line:
    "Track current nesting level using a counter and store the maximum."

Mental Shortcut:
    Open → Go Deep
    Close → Come Back

----------------------------------------------------------------------------
*/