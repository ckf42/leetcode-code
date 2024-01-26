struct Solution {
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; ++i){
            diff1 += nums[i] - (i + 1);
            diff2 += nums[i] * nums[i] - (i + 1) * (i + 1);
        }
        int missing = (diff2 / diff1 + diff1) / 2;
        return {missing, static_cast<int>(missing - diff1)};
    }
};
