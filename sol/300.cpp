#include <algorithm>

struct Solution {
    int lengthOfLIS(vector<int>& nums) {
        int tailPtr = 0;
        for (int x : nums){
            if (tailPtr == 0 || x > nums[tailPtr - 1]){
                nums[tailPtr++] = x;
            } else {
                *lower_bound(nums.begin(), nums.begin() + tailPtr, x) = x;
            }
        }
        return tailPtr;
    }
};
