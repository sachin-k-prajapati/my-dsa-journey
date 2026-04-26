/*
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Definition:
Given a Roman numeral string, convert it into its integer value.

Roman symbols:
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Special subtraction cases:
IV = 4
IX = 9
XL = 40
XC = 90
CD = 400
CM = 900

Example:
"MCMXCIV"

M  = 1000
CM = 900
XC = 90
IV = 4

Total = 1994

------------------------------------------------------------

Approach:

We compare the current symbol with the next symbol.

Rule:
- If current value < next value
  → subtract current value

- Else
  → add current value

Why?

Example:
IV

I = 1
V = 5

Since 1 < 5,
we do:
-1 + 5 = 4

This handles all subtraction cases naturally.

For normal cases like:
VI

V = 5
I = 1

Since 5 > 1,
we do:
+5 +1 = 6

------------------------------------------------------------

Key Points:

Time Complexity: O(N)

Space Complexity: O(1)

Only one traversal needed.

Very important observation:
Smaller value before larger value means subtraction.

------------------------------------------------------------

Deep Intuition:

Instead of remembering all 6 special cases separately,
just use one simple rule:

if current < next → subtract

This makes the solution very clean.

Example:
MCMXCIV

M > C → +1000
C < M → -100
M > X → +1000
X < C → -10
C > I → +100
I < V → -1
V       → +5

Final = 1994

This pattern is much better for interviews.

*/

#include <string>
using namespace std;

class Solution {
public:

    // Returns integer value of a Roman symbol
    int value(char romanSymbol) {
        if (romanSymbol == 'I') return 1;
        else if (romanSymbol == 'V') return 5;
        else if (romanSymbol == 'X') return 10;
        else if (romanSymbol == 'L') return 50;
        else if (romanSymbol == 'C') return 100;
        else if (romanSymbol == 'D') return 500;
        else if (romanSymbol == 'M') return 1000;
        else return 0;
    }

    int romanToInt(string s) {
        int n = s.length();

        int sum = 0;

        // Traverse till second last character
        for (int i = 0; i < n - 1; i++) {

            int first = value(s[i]);
            int second = value(s[i + 1]);

            // If current value is smaller than next,
            // it means subtraction case like IV, IX, XL etc.
            if (first < second) {
                sum = sum - first;
            }

            // Otherwise normal addition
            else {
                sum = sum + first;
            }
        }

        // Add the last character separately
        // because loop runs till n-2
        sum += value(s[n - 1]);

        return sum;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
String Traversal + Comparison Logic

Most Important Rule:
If current < next → subtract

Else → add

No need to memorize all special Roman cases.

Just remember:
Smaller before bigger = subtraction

Common Mistakes:
- Forgetting last character
- Hardcoding only IV, IX etc.
- Wrong subtraction handling

Interview Line:
"Compare current symbol with next symbol.
If smaller, subtract. Otherwise add."

Mental Shortcut:
Smaller before Bigger = Minus

------------------------------------------------------------
*/