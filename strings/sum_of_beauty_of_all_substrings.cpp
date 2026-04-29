/*
========================================================
1781. Sum of Beauty of All Substrings
========================================================

Problem:
Given a string s, the beauty of a substring is defined as:

Beauty = (highest frequency of any character)
         - (lowest frequency of any character excluding 0)

We need to return the sum of beauty of all possible substrings.

--------------------------------------------------------
Example:
Input: s = "aabcb"

Substrings with non-zero beauty:
["aab", "aabc", "aabcb", "abcb", "bcb"]

Each has beauty = 1

Output: 5

--------------------------------------------------------
Approach (Brute Force + Frequency Count Optimization)

We generate all possible substrings using 2 loops:

Outer loop:
-> fixes starting index i

Inner loop:
-> extends substring till index j

Instead of creating substring every time,
we maintain a frequency array of size 26.

Why?

Because string contains only lowercase English letters.

So:

frequency[0] -> count of 'a'
frequency[1] -> count of 'b'
...
frequency[25] -> count of 'z'

For every new character added:

1. Update its frequency

2. Find:
   - most frequent character
   - least frequent character (excluding frequency = 0)

3. Add:

   mostFreq - leastFreq

to final answer.

--------------------------------------------------------
Why This Works

For every starting index:

we keep expanding the substring and update frequency.

This avoids recalculating frequency from scratch.

Since only 26 characters exist,
checking max/min frequency each time is efficient.

--------------------------------------------------------
Time Complexity

Outer loop      -> O(n)
Inner loop      -> O(n)
Frequency scan  -> O(26)

Total:

O(n² * 26)

Since 26 is constant:

O(n²)

--------------------------------------------------------
Space Complexity

Frequency array of size 26:

O(26) = O(1)

--------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        // Final answer to store sum of beauty
        int beautySum = 0;

        // Fix starting index of substring
        for (int i = 0; i < n; i++) {

            // Frequency array for current substring
            vector<int> frequency(26);

            // Extend substring from i to j
            for (int j = i; j < n; j++) {

                // Include current character in frequency
                frequency[s[j] - 'a']++;

                // Track maximum and minimum frequency
                int mostFreq = INT_MIN;
                int leastFreq = INT_MAX;

                // Check all 26 lowercase letters
                for (int k = 0; k < 26; k++) {

                    // Maximum frequency
                    mostFreq = max(mostFreq, frequency[k]);

                    // Minimum frequency
                    // Ignore characters with frequency = 0
                    if (frequency[k] > 0 && frequency[k] < leastFreq) {
                        leastFreq = frequency[k];
                    }
                }

                // Add beauty of current substring
                beautySum += (mostFreq - leastFreq);
            }
        }

        return beautySum;
    }
};