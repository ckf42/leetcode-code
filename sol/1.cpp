#include <algorithm>

struct Solution {
    vector<int> twoSum(const vector<int>& nums, int target) {
        size_t i, j, n = nums.size();
        vector<int> indices;
        indices.resize(n);
        for (i = 0; i < n; ++i){
            indices[i] = i;
        }
        sort(indices.begin(), 
             indices.end(), 
             [&nums](size_t i, size_t j){return nums[i] < nums[j];});
        i = 0;
        j = n - 1;
        int sum;
        while (i < j){
            sum = nums[indices[i]] + nums[indices[j]];
            if (sum == target){
                return {indices[i], indices[j]};
            } else if (sum < target){
                ++i;
            } else {
                --j;
            }
        }
        return {0, 0};
    }
};
