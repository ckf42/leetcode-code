struct Solution {
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, flipCount = 0;
        for (int i = 0; i < n; ++i){
            if (i >= k && nums[i - k] == -1){
                --flipCount;
            }
            if ((flipCount & 1) == nums[i]){
                if (i >= n - k + 1){
                    return -1;
                }
                ++res;
                ++flipCount;
                nums[i] = -1;
            }
        }
        return res;
    }
};
