/*
 * Problem: Sort Characters By Frequency
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 *
 * Definition:
 * - Given a string s,
 *   sort characters in decreasing order of frequency.
 *
 * Rules:
 * - Higher frequency characters must come first
 * - Same frequency characters can be in any order
 * - Same characters must stay together
 *
 * Example:
 * s = "tree"
 *
 * Frequencies:
 * e → 2
 * t → 1
 * r → 1
 *
 * Output:
 * "eert" or "eetr"
 *
 * ----------------------------------------------------------------------------
 * Solution 1: Map + Vector<Pair> + Sorting
 *
 * Idea:
 *
 * Step 1:
 * - Count frequency of every character using map
 *
 * Step 2:
 * - Store into vector<pair<char, int>>
 *
 * Step 3:
 * - Sort pairs based on frequency descending
 *
 * Step 4:
 * - Build answer by repeating characters
 *
 * This is very intuitive and easy to understand.
 *
 * ----------------------------------------------------------------------------
 * Solution 2: Bucket Sort (Optimized)
 *
 * Observation:
 * - Maximum frequency can be at most N
 *
 * So:
 * - Create buckets where
 *
 *      bucket[i]
 *
 * stores characters having frequency = i
 *
 * Then:
 * - Traverse buckets from high → low
 * - Append characters frequency times
 *
 * This avoids sorting pairs explicitly.
 *
 * Better for large input sizes.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 *
 * Solution 1:
 * Time → O(N + K log K)
 *
 * Solution 2:
 * Time → O(N)
 *
 * Space → O(N)
 *
 * where:
 * K = unique characters
 *
 * ----------------------------------------------------------------------------
 * Edge Cases:
 *
 * - all same characters
 * - uppercase + lowercase difference
 * - digits included
 * - same frequency characters
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 *
 * Think:
 * "Count first, arrange later"
 *
 * Frequency problems almost always start with:
 * HashMap / Frequency Count
 *
 * Then choose:
 * - sorting
 * OR
 * - bucket optimization
 *
 * Pattern:
 *     ✔ Frequency Count
 *     ✔ Custom Sorting
 *     ✔ Bucket Sort Optimization
 *
 */

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


//
// ============================================================================
// Solution 1: Map + Sorting
// ============================================================================
//

class Solution {
public:
    string frequencySort(string s) {

        int n = s.length();

        // ------------------------------------------------
        // Step 1: Count frequency using map
        // ------------------------------------------------
        map<char, int> freqMap;

        for (int i = 0; i < n; i++) {
            if (freqMap.count(s[i])) {
                freqMap[s[i]]++;
            }
            else {
                freqMap[s[i]] = 1;
            }
        }

        // ------------------------------------------------
        // Step 2: Convert map into vector of pairs
        // ------------------------------------------------
        vector<pair<char, int>> freqPair(
            freqMap.begin(),
            freqMap.end()
        );

        // ------------------------------------------------
        // Step 3: Sort by frequency descending
        // ------------------------------------------------
        sort(freqPair.begin(), freqPair.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            }
        );

        // ------------------------------------------------
        // Step 4: Build final answer
        // ------------------------------------------------
        string ans = "";

        for (auto c : freqPair) {
            int i = 0;

            while (i++ < c.second) {
                ans += c.first;
            }
        }

        return ans;
    }
};




/*
----------------------------------------------------------------------------
Solution 2: Bucket Sort (Better Optimized)
----------------------------------------------------------------------------
*/

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        
        // Step 1: Count frequencies using a hash map
        // Time: O(N), Space: O(K) where K is unique characters
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Create buckets where the index represents frequency
        // Each bucket at index 'i' stores characters that appear 'i' times
        // Time: O(K), Space: O(N)
        vector<string> buckets(n + 1, "");
        for (auto& it : freqMap) {
            char c = it.first;
            int freq = it.second;
            buckets[freq].push_back(c);
        }

        // Step 3: Build the result string by iterating backwards from the highest frequency
        // Time: O(N), Space: O(N)
        string ans = "";
        ans.reserve(n); // Optimization: Pre-allocate memory to avoid multiple reallocations
        
        for (int i = n; i >= 1; i--) {
            if (!buckets[i].empty()) {
                for (char c : buckets[i]) {
                    // Append character 'c', 'i' times
                    ans.append(i, c);
                }
            }
        }

        return ans;
    }
};



/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------

Pattern:
    Frequency Count + Sorting

Core Idea:
    Count first
    Arrange later

Solution Choices:

1. Map + Sort
    Easier to understand

2. Bucket Sort
    Better optimized

Most Important Observation:
    Frequency max = N

That makes bucket sort possible

Why not normal sort on string?
    Because we sort by frequency,
    not lexicographical order

Common Mistakes:
    ❌ Breaking same characters apart
    ❌ Sorting alphabetically instead of frequency
    ❌ Forgetting uppercase/lowercase are different

Interview Line:
    "First count frequencies, then either sort pairs or use bucket sort."

Mental Shortcut:
    Count → Group → Build

----------------------------------------------------------------------------
*/