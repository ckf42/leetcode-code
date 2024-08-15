// wtf how do reduce memory usage?

struct Solution {
    int findNonMinOrMax(const vector<int>& nums) {
        if (nums.size() <= 2){
            return -1;
        }
        bool flag01 = nums[0] < nums[1], flag12 = nums[1] < nums[2];
        if (flag01){
            if (flag12){
                return nums[1];
            } else {
                return nums[0] < nums[2] ? nums[2] : nums[0];
            }
        } else {
            if (flag12){
                return nums[0] > nums[2] ? nums[2] : nums[0];
            } else {
                return nums[1];
            }
        }
    }
};
