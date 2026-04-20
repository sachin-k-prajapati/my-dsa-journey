#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();

        for (int i=0; i<n; i++){
            m[nums[i]] = i;
        }

        for (int i=0; i<n; i++){
            int num2 = target - nums[i];
            if (m.count(num2) && m[num2] != i) {
                return {i, m[num2]};
            }
        }
        return {};
    }
};