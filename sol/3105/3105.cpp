struct Solution {
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), inc = 1, dec = 1, res = 1;
        for (int i = 1; i < n; ++i){
            if (nums[i] > nums[i - 1]){
                dec = 1;
                res = max(res, ++inc);
            } else if (nums[i] < nums[i - 1]){
                inc = 1;
                res = max(res, ++dec);
            } else {
                inc = 1;
                dec = 1;
            }
        }
        return res;
    }
};
