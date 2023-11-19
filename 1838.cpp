#include <algorithm>

struct Solution {
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int winStart = 0;
        long winSum = 0;
        for (int targetIdx = 0; targetIdx < nums.size(); ++targetIdx){
            long target = nums[targetIdx];
            winSum += target;
            if ((targetIdx - winStart + 1) * target - winSum > k){
                winSum -= nums[winStart++];
            }
        }
        return nums.size() - winStart;
    }
};
