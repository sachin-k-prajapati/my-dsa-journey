/*
Problem: Sum of Primes Between Number and Its Reverse
Link: https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/

Definition:
Given an integer n, reverse its digits to form r.
Find all prime numbers in the range [min(n, r), max(n, r)] (inclusive)
and return their sum.

------------------------------------------------------------

Approach:

Brute Force + Optimized Prime Check

Steps:
1. Reverse the number → r
2. Find range:
        start = min(n, r)
        end   = max(n, r)
3. Traverse all numbers in range:
        → Check if prime
        → Add to sum

------------------------------------------------------------

Why this works:

Constraints are small:
n ≤ 1000 → max range ~1000

So brute force with optimized prime check is efficient.

------------------------------------------------------------

Key Points:

Time Complexity:
O(N * sqrt(N))   (prime check for each number)

Space Complexity:
O(1)

------------------------------------------------------------

Edge Cases:

- n == reverse(n) → single number range
- Range has no primes → return 0
- n = 1 → no primes
- Leading zeros in reverse (e.g., 10 → 01 → 1)

------------------------------------------------------------

Deep Intuition:

Instead of generating primes beforehand,
we check each number efficiently using:

Optimized Prime Check:
→ Check till sqrt(n)
→ Skip multiples using 6k ± 1 rule

------------------------------------------------------------

Pattern:

Math + Number Manipulation + Prime Optimization

------------------------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Optimized prime check
    bool isPrimeNumber(int number) {

        // 0,1 are not prime
        if (number <= 1) return false;

        // 2,3 are prime
        if (number <= 3) return true;

        // Eliminate multiples of 2 and 3
        if (number % 2 == 0 || number % 3 == 0) return false;

        // Check only 6k ± 1 numbers
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    // Reverse digits of number
    int reverseNumber(int n) {
        int number = 0;

        while (n > 0) {
            int lastDigit = n % 10;
            number = number * 10 + lastDigit;
            n /= 10;
        }

        return number;
    }

    int sumOfPrimesInRange(int n) {

        int sumOfPrimes = 0;

        // Step 1: reverse number
        int reversed = reverseNumber(n);

        // Step 2: determine range
        int minimum = min(reversed, n);
        int maximum = max(reversed, n);

        // Step 3: iterate through range
        for (int start = minimum; start <= maximum; start++) {

            if (isPrimeNumber(start)) {
                sumOfPrimes += start;
            }

        }

        return sumOfPrimes;
    }
};


/*
------------------------------------------------------------
Notes for Revision:

Pattern:
Math + Range Iteration + Prime Checking

------------------------------------------------------------

Core Idea:

Reverse → define range → sum primes

------------------------------------------------------------

Prime Optimization:

Check:
❌ up to n
✅ only up to sqrt(n)

Skip:
→ even numbers
→ multiples of 3

------------------------------------------------------------

6k ± 1 Rule:

All primes > 3 are of form:
6k - 1 OR 6k + 1

------------------------------------------------------------

Common Mistakes:

❌ Checking all numbers till n
❌ Not handling reverse correctly
❌ Including 1 as prime
❌ Ignoring range order

------------------------------------------------------------

Interview Line:

"Reverse the number, iterate range, and use optimized prime check."

------------------------------------------------------------

Mental Model:

n → reverse(n)

Define interval
Check each number efficiently

------------------------------------------------------------
*/