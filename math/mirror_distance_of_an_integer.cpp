/*
Problem: Mirror Distance of an Integer
Link: https://leetcode.com/problems/mirror-distance-of-an-integer/

Definition:
Given an integer n,

Mirror Distance is defined as:

abs(n - reverse(n))

where:
reverse(n) means reversing the digits of n.

Return the mirror distance.

Examples:

n = 25

reverse(25) = 52

answer = abs(25 - 52)
       = 27


n = 10

reverse(10) = 01 = 1

answer = abs(10 - 1)
       = 9

------------------------------------------------------------

Approach:

This problem has 2 simple steps:

Step 1:
Reverse the number

Step 2:
Return absolute difference between
original number and reversed number

To reverse:

Example:
n = 123

Take last digit repeatedly:

123 % 10 = 3
12  % 10 = 2
1   % 10 = 1

Build:

0 → 3 → 32 → 321

Final reversed number = 321

------------------------------------------------------------

Key Points:

Time Complexity: O(log10 n)

Because number of digits is processed

Space Complexity: O(1)

Only constant variables used

------------------------------------------------------------

Deep Intuition:

This is a classic number manipulation problem.

Core idea:

Take digits from right
Build number from left

Very common pattern in:

- Reverse Integer
- Palindrome Number
- Digit Sum problems

Example:

n = 340

reverse:

340 → 043 → 43

Leading zero disappears automatically
because integer storage ignores it.

That is why:
reverse(10) = 1

not 01

*/

#include <cmath>
using namespace std;

class Solution {
public:

    // Function to reverse the digits of a number
    int reverse(int n) {
        int reversedNum = 0;

        while (n > 0) {

            // Extract last digit
            int lastDigit = n % 10;

            // Remove last digit from original number
            n /= 10;

            // Shift previous digits left
            reversedNum *= 10;

            // Add extracted digit
            reversedNum += lastDigit;
        }

        return reversedNum;
    }

    int mirrorDistance(int n) {

        // Get reversed number
        int reversed = reverse(n);

        // Return absolute difference
        return abs(n - reversed);
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Number Manipulation

Core Formula:

Mirror Distance =
abs(original - reversed)

Reverse Logic:

Take last digit
→ add to new number

Formula:

lastDigit = n % 10
n /= 10

reversed = reversed * 10 + lastDigit

Very Important:

Leading zero disappears automatically

Example:
10 → 01 → 1

Common Mistakes:

- forgetting reversed *= 10
- wrong digit extraction
- confusion with leading zeros

Interview Line:

"Reverse the integer digit by digit,
then return absolute difference."

Mental Shortcut:

Extract → Build → Compare

------------------------------------------------------------
*/