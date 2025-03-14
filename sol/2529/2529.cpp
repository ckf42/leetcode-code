#include <algorithm>

struct Solution {
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = n - (std::upper_bound(nums.begin() + neg, nums.end(), 0) - nums.begin());
        return max(pos, neg);
    }
};
