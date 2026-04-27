/*
Problem: String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/

Definition:
Convert a string into a 32-bit signed integer.

Rules:

1. Ignore leading whitespaces
2. Check optional sign (+ or -)
3. Read continuous digits only
4. Stop when first invalid character appears
5. Clamp answer inside:
   [-2^31 , 2^31 - 1]

Return final integer.

Examples:

"42" → 42

"   -042" → -42

"1337c0d3" → 1337

"words and 987" → 0

"2147483648" → 2147483647

------------------------------------------------------------

Approach:

We process the string character by character.

Track:

1. leading whitespaces
2. sign (+ / -)
3. valid digits
4. overflow handling

Main idea:

- Skip spaces first
- Detect sign only once
- Start building number only when digit comes
- Stop immediately when invalid character appears

Important:
Use long long while building number
to safely detect overflow before int conversion.

------------------------------------------------------------

Key Points:

Time Complexity: O(N)

Space Complexity: O(1)

Very important:
Overflow must be handled before final return.

That is why:
long long is used.

------------------------------------------------------------

Deep Intuition:

This problem is not just number conversion.

It tests:

- string parsing
- condition handling
- sign management
- overflow safety
- edge case thinking

Example:

"   -42abc"

skip spaces
detect '-'
read 4
read 2
stop at 'a'

answer = -42

Example:

"91283472332"

This exceeds INT_MAX

so answer must be:
2147483647

This is where many mistakes happen.

*/

#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        // Use long long to safely detect overflow
        long long int number = 0;

        // signbit = 1 means positive
        // signbit = -1 means negative
        int signbit = 1;

        // To ensure sign is processed only once
        bool sign = false;

        // To know if digit reading has started
        bool digit = false;

        // Used to skip only leading spaces
        bool whitespaces = true;

        for (auto c : s) {

            // Ignore only leading spaces
            if (c == ' ' && whitespaces) {
                continue;
            }

            else {
                whitespaces = false;

                // If current character is digit
                if (c >= '0' && c <= '9') {

                    digit = true;

                    // Build number
                    number *= 10;
                    number += (c - '0');

                    // Overflow handling
                    if (number > INT_MAX) {

                        // Negative overflow
                        if (signbit == -1) {
                            return INT_MIN;
                        }

                        // Positive overflow
                        else {
                            return INT_MAX;
                        }
                    }
                }

                // Handle negative sign
                // Only allowed before digits start
                else if (c == '-' && !sign && !digit) {
                    sign = true;
                    signbit = -1;
                }

                // Handle positive sign
                else if (c == '+' && !sign && !digit) {
                    sign = true;
                }

                // Any invalid case → stop reading
                else {
                    break;
                }
            }
        }

        // Apply sign and return final result
        return (int)(signbit * number);
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
String Parsing + Overflow Handling

Order matters:

1. Skip spaces
2. Detect sign
3. Read digits
4. Stop on invalid char

Most Important Part:
Overflow check before final return

Why long long?
Because int may overflow
before comparison happens

Common Mistakes:

- allowing multiple signs
- reading spaces after sign
- missing overflow handling
- forgetting invalid early break

Interview Line:

"Parse step by step and use long long
to safely handle overflow."

Mental Shortcut:

Skip → Sign → Digits → Clamp

------------------------------------------------------------
*/