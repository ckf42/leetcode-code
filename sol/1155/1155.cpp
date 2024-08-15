struct Solution {
    constexpr static int M = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        if (target < 0 || target > n * k){
            return 0;
        }
        if (target == k * n){
            return 1;
        }
        if (target == 0){
            return n == 0 ? 1 : 0;
        }
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int d = 1; d <= n; ++d){
            for (int p = min(target, d * k); p >= d; --p){
                dp[p] = 0;
                for (int f = 1; f <= min(k, p - d + 1) ; ++f){
                    dp[p] = (dp[p] + dp[p - f]) % this->M;
                }
            }
        }
        return dp[target];
    }
};
