#include <algorithm>

struct Solution {
    int minOperations(vector<int>& nums) {
        size_t size = nums.size(), j = 0;
        size_t ans = size;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (size_t i = 0; i < nums.size(); ++i){
            while (j < nums.size() && nums[j] < nums[i] + size){
                ++j;
            }
            ans = min(ans, size - j + i);
        }
        return ans;
    }
};
