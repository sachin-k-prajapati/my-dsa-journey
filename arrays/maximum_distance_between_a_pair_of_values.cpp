/* # 1855. Maximum Distance Between a Pair of Values

## 🧠 Approach: Two Pointers

Since both arrays are **non-increasing**, we use a two-pointer technique:

- Initialize `i = 0`, `j = 0`
- If `nums1[i] <= nums2[j]`:
  - Valid pair → update distance
  - Move `j++` to maximize distance
- Else:
  - Move `i++` to reduce value
- Ensure `j >= i`

---

## ⏱ Complexity

- Time: O(n + m)
- Space: O(1)

---

## 💡 Key Insight

Monotonic arrays allow us to **greedily expand `j`** without revisiting elements.

---

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int maxDist = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++;
            } else {
                i++;
                if (j < i) j = i;
            }
        }

        return maxDist;
    }
};