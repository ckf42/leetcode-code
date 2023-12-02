#include <algorithm>

struct Solution {
    vector<int> getSumAbsoluteDifferences(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(nums.size(), 0);
        int totalSum = reduce(nums.cbegin(), nums.cend());
        for (int i = 0; i < n; ++i){
            res[i] = totalSum - (n - (i << 1)) * nums[i];
            totalSum -= (nums[i]) << 1;
        }
        return res;
    }
};
