struct Solution {
    int maximumBeauty(vector<int>& nums, int k) {
        int minval = *ranges::min_element(nums) - k, maxval = *ranges::max_element(nums) + k;
        vector<int> memo(maxval - minval + 2, 0);
        for (int x : nums){
            ++memo[x - k - minval];
            --memo[x + k + 1 - minval];
        }
        int res = 1, cumsum = 0;
        for (int x : memo){
            cumsum += x;
            res = max(res, cumsum);
        }
        return res;
    }
};
