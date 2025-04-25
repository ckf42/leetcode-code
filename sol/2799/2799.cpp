#include <unordered_set>

struct Solution {
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), l = 0, res = 0, uqCount = 0;
        int freq[2001] = {0};
        unordered_set<int> uniqSet;
        uniqSet.insert(nums.begin(), nums.end());
        int totalUniq = uniqSet.size();
        for (int r = 0; r < n; ++r){
            if (++freq[nums[r]] == 1){
                ++uqCount;
            }
            while (l <= r && uqCount == totalUniq){
                if (--freq[nums[l++]] == 0){
                    --uqCount;
                }
            }
            res += l;
        }
        return res;
    }
};
