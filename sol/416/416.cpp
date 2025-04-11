struct Solution {
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), total = reduce(nums.begin(), nums.end());
        if (total & 1){
            return false;
        }
        int target = total >> 1;
        vector<bool> memo(target + 1, false);
        memo[target] = true;
        for (int x : nums){
            for (int i = 0; i <= target - x; ++i){
                memo[i] = memo[i] || memo[i + x];
            }
        }
        return memo[0];
    }
};
