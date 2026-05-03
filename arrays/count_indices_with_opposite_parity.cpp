/*
Problem: Count Indices With Opposite Parity
Link: https://leetcode.com/problems/count-indices-with-opposite-parity/

Definition:
For each index i, count how many indices j exist such that:
- i < j
- nums[i] and nums[j] have opposite parity (one odd, one even)

Return an array where answer[i] = count of such indices.

------------------------------------------------------------

Approach:

Reverse Traversal + Counting

- Traverse from RIGHT → LEFT
- Maintain:
    odd → count of odd numbers seen so far (to the right)
    even → count of even numbers seen so far (to the right)

For each index i:
    if nums[i] is odd → result[i] = even
    if nums[i] is even → result[i] = odd

Then update counts accordingly.

------------------------------------------------------------

Why this works:

We only care about elements AFTER index i

By traversing from right:
→ We already know how many odds/even exist after i

------------------------------------------------------------

Key Points:

Time Complexity: O(N)
Space Complexity: O(1) (excluding output array)

------------------------------------------------------------

Edge Cases:

- Single element → always 0
- All even or all odd → all answers 0
- Mixed array → handled naturally

------------------------------------------------------------

Deep Intuition:

Instead of checking every j > i (O(N²)),
we pre-count future values using reverse traversal.

So each index is answered in O(1)

------------------------------------------------------------

Pattern:

Suffix Counting / Reverse Traversal Optimization

------------------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int odd = 0;   // count of odd numbers to the right
        int even = 0;  // count of even numbers to the right

        vector<int> result(nums.size());

        // Traverse from right to left
        for (int i = nums.size() - 1; i >= 0; i--) {

            // If current number is odd
            if (nums[i] % 2 == 1) {
                // Opposite parity → even numbers
                result[i] = even;

                // Update odd count
                odd++;
            }
            else {
                // Opposite parity → odd numbers
                result[i] = odd;

                // Update even count
                even++;
            }
        }

        return result;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Suffix Counting / Reverse Thinking

------------------------------------------------------------

Core Idea:

Instead of checking all j > i,
keep track of counts of future elements

------------------------------------------------------------

Why reverse?

Because:
→ Future elements become "known" as we move backward

------------------------------------------------------------

Key Trick:

For each element:
→ Answer = count of opposite parity elements seen so far

------------------------------------------------------------

Common Mistakes:

❌ Using nested loops (O(N²))
❌ Counting left side instead of right side
❌ Forgetting to update counts AFTER using them

------------------------------------------------------------

Interview Line:

"Use reverse traversal and maintain counts of odd and even."

------------------------------------------------------------

Mental Model:

Right side already processed
→ Just pick count instantly

------------------------------------------------------------
*/