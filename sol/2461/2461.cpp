#include <unordered_map>

struct Solution {
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), rep = 0;
        long long res = 0, total = 0;
        unordered_map<int, int> d;
        for (int i = 0; i < k; ++i){
            if (++d[nums[i]] == 2){
                ++rep;
            }
            total += nums[i];
        }
        if (rep == 0){
            res = total;
        }
        for (int i = k; i < n; ++i){
            total += nums[i];
            if (++d[nums[i]] == 2){
                ++rep;
            }
            total -= nums[i - k];
            if (--d[nums[i - k]] == 1){
                --rep;
            }
            if (rep == 0){
                res = max(res, total);
            }
        }
        return res;
    }
};
