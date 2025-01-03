struct Solution {
    int waysToSplitArray(vector<int>& nums) {
        long total = 0, curr = 0;
        for (int x : nums){
            total += x;
        }
        int res = 0, n = nums.size();
        for (int i = 0; i < n - 1; ++i){
            curr += nums[i];
            res += (curr * 2 >= total);
        }
        return res;
    }
};
