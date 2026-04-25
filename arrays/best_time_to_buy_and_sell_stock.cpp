/*
 * Problem: Best Time to Buy and Sell Stock
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Definition:
 * - Given an array prices where prices[i] is the stock price on day i,
 *   choose ONE day to buy and ONE future day to sell to maximize profit.
 * - Return the maximum profit. If no profit possible → return 0.
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Traverse the array once while maintaining:
 *     1. Minimum price seen so far (mini)
 *     2. Maximum price after that minimum (maxi)
 * - At each step:
 *     - If a new smaller price appears → update mini (new buying point).
 *     - If current price gives better selling opportunity → update maxi.
 *     - Calculate profit = maxi - mini and track maximum.
 *
 * Justification:
 * - Instead of checking all pairs (O(N^2)), we track best buy and sell dynamically.
 * - Ensures buy always happens before sell.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N) → single pass
 * - Space Complexity: O(1)
 * - Handles:
 *     - Strictly decreasing prices → profit = 0
 *     - Single element → profit = 0
 * - Important condition:
 *     - If min index becomes ahead of max index → reset selling candidate
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of it as:
 *     "Find the lowest valley before a peak"
 * - mini = best buying point so far
 * - maxi = best selling point AFTER that mini
 *
 * - If a new lower price appears:
 *     → previous profit chain breaks → restart buying from here
 *
 * - This ensures:
 *     - We never sell before buying
 *     - We always consider best possible profit till current index
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();

        // Initialize tracking variables
        int mini = prices[0], maxi = prices[0];
        int minIdx = 0, maxIdx = 0;

        int maxProfit = 0;

        for (int i = 0; i < length; i++) {

            // Update minimum price (best buying point)
            if (prices[i] < mini) {
                mini = prices[i];
                minIdx = i;
            }

            // Update maximum price (best selling point)
            // Important: ensure sell happens after buy
            if (maxIdx < minIdx || prices[i] > maxi) {
                maxi = prices[i];
                maxIdx = i;
            }

            // Calculate current profit
            maxProfit = max(maxProfit, maxi - mini);
        }

        return maxProfit;
    }
};


// ----------------------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Minimum buying price seen so far
        int minPrice = prices[0];

        // Best profit found so far
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            // Calculate profit if sold today
            int currentProfit = prices[i] - minPrice;

            // Update best profit
            maxProfit = max(maxProfit, currentProfit);

            // Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Always maintain "minimum so far" → key pattern in many problems.
- This is a classic greedy + single pass optimization problem.
- Common mistake:
    ❌ Trying all pairs (O(N^2))
    ❌ Not ensuring buy < sell

- Alternative simpler pattern (mental shortcut):
    profit = max(profit, price[i] - minSoFar)

----------------------------------------------------------------------------
*/