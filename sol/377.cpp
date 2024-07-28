#include <unordered_map>

struct Solution {
    int dpf(int n, unordered_map<int, int> &dp, const vector<int>& nums){
        unordered_map<int, int>::iterator it = dp.find(n);
        if (it != dp.end()){
            return it->second;
        }
        int total = 0;
        for (int c: nums){
            if (n >= c){
                total += dpf(n - c, dp, nums);
            }
        }
        dp[n] = total;
        return total;
    }
    int combinationSum4(const vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        return dpf(target, dp, nums);
    }
};
