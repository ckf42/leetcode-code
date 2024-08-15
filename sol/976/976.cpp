#include <algorithm>

struct Solution {
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a;
        for (size_t i = nums.size() - 1; i >= 2; --i){
            a = nums[i - 1] + nums[i - 2];
            if (nums[i] < a){
                return nums[i] + a;
            }
        }
        return 0;
    }
};
