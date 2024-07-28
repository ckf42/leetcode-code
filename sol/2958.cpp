#include <unordered_map>

struct Solution {
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int res = 0, s = 0;
        for (int e = 0; e < nums.size(); ++e){
            ++freq[nums[e]];
            while (freq[nums[e]] > k){
                --freq[nums[s++]];
            }
            res = max(res, e - s + 1);
        }
        return res;
    }
};
