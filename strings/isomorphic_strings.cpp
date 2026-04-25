/*
 * Problem: Isomorphic Strings
 * Link: https://leetcode.com/problems/isomorphic-strings/
 *
 * Definition:
 * - Two strings s and t are isomorphic if characters in s
 *   can be replaced to get t.
 *
 * Rules:
 * - Same character must always map to same character
 * - Two different characters cannot map to same character
 * - Character may map to itself
 *
 * Example:
 * s = "egg"
 * t = "add"
 *
 * e → a
 * g → d
 *
 * Valid → return true
 *
 * Example:
 * s = "foo"
 * t = "bar"
 *
 * f → b
 * o → a and r (conflict)
 *
 * Invalid → return false
 *
 * ----------------------------------------------------------------------------
 * Approach 1: Two Pass Mapping Check
 *
 * Idea:
 * - First check mapping:
 *      s → t
 *
 * - Then check reverse mapping:
 *      t → s
 *
 * Why reverse check needed?
 *
 * Example:
 * s = "ab"
 * t = "aa"
 *
 * Forward mapping:
 * a → a
 * b → a
 *
 * Looks valid from one side,
 * but actually invalid because
 * two chars cannot map to same char.
 *
 * Reverse check catches this.
 *
 * ----------------------------------------------------------------------------
 * Approach 2: Simultaneous Two HashMaps (Better)
 *
 * Use:
 * - s2t → mapping from s to t
 * - t2s → mapping from t to s
 *
 * At every index:
 * - Validate both directions together
 *
 * This is cleaner and more interview preferred.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * (ASCII characters → bounded space)
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - repeated same characters
 * - same string
 * - one-to-many mapping invalid
 * - many-to-one mapping invalid
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Mapping must be one-to-one"
 *
 * Not just:
 * s → t
 *
 * But also:
 * t → s
 *
 * Bidirectional validation is the real key.
 *
 * Pattern:
 *     ✔ HashMap
 *     ✔ Character Mapping
 *     ✔ Bidirectional Validation
 *
 */

#include <string>
#include <unordered_map>
using namespace std;


// ============================================================================
// Solution 1: Two Pass HashMap Validation
// ============================================================================

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = s.size();

        // Mapping from s -> t
        unordered_map<char, char> hashMap;

        // ------------------------------------------------
        // First pass:
        // Validate s -> t mapping
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {

            if (hashMap.count(s[i])) {

                // Existing mapping must match
                if (hashMap[s[i]] != t[i]) {
                    return false;
                }

            } else {

                // Create new mapping
                hashMap[s[i]] = t[i];
            }
        }

        // Clear and reuse for reverse check
        hashMap.clear();

        // ------------------------------------------------
        // Second pass:
        // Validate t -> s mapping
        // ------------------------------------------------
        for (int i = 0; i < n; i++) {

            if (hashMap.count(t[i])) {

                if (hashMap[t[i]] != s[i]) {
                    return false;
                }

            } else {

                hashMap[t[i]] = s[i];
            }
        }

        return true;
    }
};


/*
----------------------------------------------------------------------------
Approach 2: Better Clean Version (Two Maps Together)
----------------------------------------------------------------------------
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // s → t mapping
        unordered_map<char, char> s2t;

        // t → s mapping
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {

            // ------------------------------------------------
            // Check existing mapping from s to t
            // ------------------------------------------------
            if (s2t.count(s[i]) && s2t[s[i]] != t[i]) {
                return false;
            }

            // ------------------------------------------------
            // Check existing mapping from t to s
            // ------------------------------------------------
            if (t2s.count(t[i]) && t2s[t[i]] != s[i]) {
                return false;
            }

            // Store/update both mappings
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }

        return true;
    }
};


/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    HashMap + Character Mapping

Most Important Rule:
    Mapping must be ONE-to-ONE

Not enough:
    s → t

Also needed:
    t → s

Why?
    To prevent:
        many → one mapping

Classic Wrong Example:
    s = "ab"
    t = "aa"

Forward seems valid
Actually invalid

So:
    Bidirectional check is mandatory

Better Interview Solution:
    Use two maps simultaneously

Common Mistakes:
    ❌ Checking only one direction
    ❌ Ignoring reverse conflict
    ❌ Using set only

Interview Line:
    "Validate bijection using two hashmaps."

Mental Shortcut:
    Forward + Reverse = Safe Mapping

----------------------------------------------------------------------------
*/