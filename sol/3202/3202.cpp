struct Solution {
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 2){
            return n;
        }
        for (int &x : nums){
            x %= k;
        }
        int res = 1;
        for (int rem = 0; rem < k; ++rem){
            vector<int> memo(k, 0);
            for (int x : nums){
                memo[x] = memo[(rem + k - 1 - x) % k] + 1;
                res = max(res, memo[x]);
            }
        }
        return res;
    }
};
