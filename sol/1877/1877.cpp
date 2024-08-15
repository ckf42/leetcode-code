#include <algorithm>

struct Solution {
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[n - 1];
        for (int i = 1; i < n / 2 ; ++i){
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};
