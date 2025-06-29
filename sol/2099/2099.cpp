#include <ranges>

struct Solution {
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> indices(n);
        ranges::iota(indices, 0);
        ranges::sort(indices, [&](int i, int j){return nums[i] > nums[j];});
        ranges::sort(indices.begin(), indices.begin() + k);
        return views::take(indices, k) 
            | views::transform([&](int i){return nums[i];}) 
            | ranges::to<vector>();
    }
};
