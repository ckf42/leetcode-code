struct Solution {
    using ll = long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> memo(k, 0);
        ll winsum = 0;
        for (int i = 0; i < k; ++i){
            winsum += nums[i];
        }
        memo[k - 1] = winsum;
        ll res = winsum;
        for (int i = k; i < n; ++i){
            winsum += nums[i] - nums[i - k];
            int j = i % k;
            memo[j] = max(memo[j] + winsum, winsum);
            res = max(res, memo[j]);
        }
        return res;
    }
};
