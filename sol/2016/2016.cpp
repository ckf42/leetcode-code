struct Solution {
    int maximumDifference(vector<int>& nums) {
        int res = -1, mini = nums[0], n = nums.size();
        for (int i = 1; i < n; ++i){
            if (nums[i] <= mini){
                mini = nums[i];
            } else {
                res = max(res, nums[i] - mini);
            }
        }
        return res;
    }
};
