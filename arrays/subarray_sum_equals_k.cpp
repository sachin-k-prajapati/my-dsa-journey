/*
 * Problem: Subarray Sum Equals K
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * Definition:
 * - Given an array nums and integer k,
 *   return the number of subarrays whose sum equals k.
 * - Subarray must be contiguous.
 *
 * Example:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * - Use Prefix Sum + Hash Map
 *
 * Key Idea:
 * Let prefix sum at index i = sum
 * We want:
 *     sum[j] - sum[i] = k
 * → sum[i] = sum[j] - k
 *
 * So:
 * - While traversing, keep track of prefix sums
 * - Check if (current_sum - k) exists before
 *
 * Steps:
 * 1. Maintain running sum
 * 2. If sum == k → one valid subarray
 * 3. If (sum - k) exists in map → add its frequency
 * 4. Store current sum in map
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * Why hashmap?
 * - Stores frequency of prefix sums for quick lookup
 *
 * Edge Cases:
 * - Negative numbers present → sliding window won't work
 * - Multiple overlapping subarrays
 * - k = 0
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Instead of checking all subarrays (O(N²)),
 *   we use prefix sums to reduce it to O(N).
 *
 * - Think:
 *     "Have I seen a prefix that makes current sum = k?"
 *
 * - If current sum = S,
 *     we need previous prefix = (S - k)
 *
 * - Pattern:
 *     ✔ Prefix Sum + Hashing
 *     ✔ Subarray count problems
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int sum = 0;
        int count = 0;

        unordered_map<int, int> mp;         // prefix sum → frequency

        for (int i = 0; i < n; i++) {
            sum += nums[i]; // update running sum
            
            // Case 1: subarray from index 0 to i with sum k ----> as [0 -> i] = sum, if sum == k → valid subarray
            if (sum == k) {
                count++;
            }

            // Case 2: subarray ending at i with sum k
            if (mp.find(sum - k) != mp.end()) {             // If (sum - k) exists in map → add its frequency to count because each occurrence can form a valid subarray with current sum
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }
        
        return count;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Prefix Sum + HashMap"
- Key identity:
    sum[j] - sum[i] = k

- Always:
    ✔ Track prefix sum
    ✔ Check (sum - k) in map

- Common mistakes:
    ❌ Trying sliding window (fails with negatives)
    ❌ Forgetting multiple occurrences (frequency matters)

- Mental model:
    "Count how many previous sums can form k with current sum"

----------------------------------------------------------------------------
*/