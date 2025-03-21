struct Solution {
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1, n = nums.size(), mask = nums[0], l = 0;
        for (int r = 1; r < n; ++r){
            while (l < r && (mask & nums[r]) != 0){
                mask ^= nums[l++];
            }
            mask |= nums[r];
            res = max(res, r - l + 1);
        }
        return res;
    }
};
