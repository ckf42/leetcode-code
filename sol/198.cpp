struct Solution {
    int rob(const vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int prev = nums[0], val = max(nums[0], nums[1]), temp;
        for (int i = 2; i < nums.size(); ++i){
            temp = prev;
            prev = val;
            val = max(temp + nums[i], prev);
        }
        return val;
    }
};
