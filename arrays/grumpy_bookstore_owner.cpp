// Problem: 1052. Grumpy Bookstore Owner
// Link: https://leetcode.com/problems/grumpy-bookstore-owner/
// Difficulty: Medium
//
// Description:
// A bookstore owner is open for `n` minutes. 
// - customers[i] = number of customers entering at minute i
// - grumpy[i] = 1 if owner is grumpy at minute i, else 0
//
// When grumpy, customers are unsatisfied. 
// Owner can use a "secret technique" for exactly `minutes` consecutive minutes 
// to avoid being grumpy. This can be used only once.
// Return the maximum number of satisfied customers possible.
//
// Constraints:
// n == customers.length == grumpy.length
// 1 <= minutes <= n <= 2 * 10^4
// 0 <= customers[i] <= 1000
// grumpy[i] is either 0 or 1
//
// ---------------------------------------------------------------------------
// Example:
// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
// Explanation: Activate technique in last 3 minutes → satisfied = 1+1+1+1+7+5 = 16
// ---------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ============================================================================
// First Attempt (Queue-based Window Tracking)
// ============================================================================
// Idea:
// 1. First, find the index of the best `minutes` window to apply the technique.
//    - Use a queue to store indices of grumpy minutes within the current window.
//    - Track the sum of customers in these grumpy minutes for the window.
// 2. Once we find the best starting index, calculate the final satisfied count:
//    - Inside that window: count all customers
//    - Outside: count only non-grumpy customers
//
// Time: O(N) — single pass to find window, then single pass for sum
// Space: O(M) — queue for tracking indices (M = window size)
// ============================================================================
class SolutionFirst {
public:
    int findNotGrumpy(vector<int>& customers, vector<int>& grumpy, int minutes) {
        queue<int> track; // indices of grumpy minutes in current window
        int maxSum = 0, sum = 0, index = 0;

        // Initial window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) {
                sum += customers[i];
                track.push(i);
            }
        }
        maxSum = sum;

        // Slide the window
        for (int i = 0; i < (int)customers.size() - minutes; i++) {
            // Add new element if grumpy
            if (grumpy[i + minutes]) {
                if (!track.empty() && ((i + minutes) - track.front()) >= minutes) {
                    sum -= customers[track.front()];
                    track.pop();
                }
                sum += customers[i + minutes];
                track.push(i + minutes);
            } else {
                // Remove outdated grumpy entry
                if (!track.empty() && ((i + minutes) - track.front()) >= minutes) {
                    sum -= customers[track.front()];
                    track.pop();
                }
            }

            if (sum > maxSum) {
                maxSum = sum;
                index = i + 1;
            }
        }
        return index;
    }

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int index = findNotGrumpy(customers, grumpy, minutes);
        int satisfied = 0;

        // Calculate total satisfaction using best window
        for (int i = 0; i < (int)customers.size(); i++) {
            if (i >= index && i < (index + minutes)) {
                satisfied += customers[i]; // in chosen window, all satisfied
            } else if (!grumpy[i]) {
                satisfied += customers[i]; // outside window, only non-grumpy
            }
        }
        return satisfied;
    }
};

// ============================================================================
// Improved Solution (Sliding Window, O(1) Memory)
// ============================================================================
// Idea:
// 1. First count the baseline satisfaction (all non-grumpy minutes).
// 2. Use a sliding window of size `minutes` to find the max extra satisfaction
//    possible by making grumpy minutes satisfied.
// 3. Return baseline + best extra.
//
// Time: O(N)
// Space: O(1)
// ============================================================================
class SolutionOptimized {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;

        // Baseline: satisfied customers when not grumpy
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) satisfied += customers[i];
        }

        // First window extra satisfaction
        int maximizeSum = 0, maxSum = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) maximizeSum += customers[i];
        }
        maxSum = max(maximizeSum, maxSum);

        // Slide window
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) maximizeSum += customers[i];
            if (grumpy[i - minutes] == 1) maximizeSum -= customers[i - minutes];
            maxSum = max(maximizeSum, maxSum);
        }

        return satisfied + maxSum;
    }
};

// ============================================================================
// Notes:
// - The optimized version is more memory efficient and easier to implement.
// - First solution is conceptually fine but unnecessarily tracks indices.
// - Always start by separating "baseline" and "extra" to simplify logic.
// ============================================================================

int main() {
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy =    {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    SolutionFirst sol1;
    SolutionOptimized sol2;

    cout << "First Solution Output: " << sol1.maxSatisfied(customers, grumpy, minutes) << endl;
    cout << "Optimized Solution Output: " << sol2.maxSatisfied(customers, grumpy, minutes) << endl;

    return 0;
}
