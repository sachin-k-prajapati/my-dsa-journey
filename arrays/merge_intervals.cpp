/*
 * Problem: Merge Intervals
 * Link: https://leetcode.com/problems/merge-intervals/
 *
 * Definition:
 * - Given intervals [start, end], merge all overlapping intervals.
 * - Return a list of non-overlapping intervals covering all input intervals.
 *
 * Example:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 *
 * ----------------------------------------------------------------------------
 * Approach:
 * 1. Sort intervals by starting time.
 * 2. Traverse intervals and keep track of:
 *      - current interval start
 *      - current maximum end (maxEnd)
 *
 * 3. For each next interval:
 *      - If overlap:
 *            extend maxEnd = max(maxEnd, nextEnd)
 *      - If no overlap:
 *            store current interval
 *            start a new one
 *
 * 4. Push the last interval at the end.
 *
 * Justification:
 * - Sorting ensures overlapping intervals come together.
 * - Greedy merging works because we always extend the current range optimally.
 *
 * ----------------------------------------------------------------------------
 * Key Points:
 * - Time Complexity: O(N log N) → sorting dominates
 * - Space Complexity: O(N) → result array
 *
 * Edge Cases:
 * - Single interval → return as is
 * - Fully overlapping intervals
 * - Touching intervals (e.g., [1,4] & [4,5]) → considered overlapping
 *
 * ----------------------------------------------------------------------------
 * Intuition:
 * - Think of intervals as ranges on a number line.
 *
 * - If next interval starts BEFORE current ends → overlap
 *     → merge by extending the end
 *
 * - If next interval starts AFTER current ends → no overlap
 *     → finalize current and start new
 *
 * - Greedy insight:
 *     Always extend as far as possible before committing interval.
 */

// -------------------------
// Final Code (Your Solution)
// -------------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // Initialize first interval
        int start = intervals[0][0];
        int maxEnd = intervals[0][1];   // current max end

        for (int i = 0; i < n - 1; i++) {
            int end = intervals[i][1];
            int nextStart = intervals[i + 1][0];    // next interval's start
            int nextEnd = intervals[i + 1][1];  // next interval's end

            // If no overlap → store current interval because next interval starts after current max end
            if (maxEnd < nextStart) {               //comparing current max end with next interval's start because if next interval's start is greater than current max end, it means there is no overlap
                ans.push_back({start, maxEnd});     // push current interval
                start = nextStart;                  // assign next interval's start to current start
                maxEnd = nextEnd;                   // reset maxEnd to next interval's end
            }

            // If overlap → extend the interval because next interval's start is less than or equal to current max end, it means there is an overlap and we need to extend the current interval's end to the maximum of current max end and next interval's end
            maxEnd = max(maxEnd, nextEnd);
        }

        // Push the last interval after the loop because it won't be pushed inside the loop since we are always running loop n-1 time & comparing with the next interval and the last interval won't have a next interval to compare with, so we need to push it after the loop
        ans.push_back({start, maxEnd});

        return ans;
    }
};

/*
----------------------------------------------------------------------------
🧠 Notes for Revision:
----------------------------------------------------------------------------
- Pattern: "Sorting + Greedy merging"
- Core idea:
    ✔ Sort intervals → process sequentially
    ✔ Merge overlapping ranges

- Overlap condition:
    nextStart <= currentEnd

- Common mistakes:
    ❌ Forgetting to sort
    ❌ Not pushing last interval
    ❌ Using wrong overlap condition

- Mental model:
    "Stretch current interval until it breaks"

----------------------------------------------------------------------------
*/