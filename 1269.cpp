struct Solution {
    int numWays(int steps, int arrLen) {
        const int m = 1000000007;
        arrLen = min(arrLen, steps / 2 + 1);
        if (arrLen == 1){
            return 1;
        }
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        int prev = 0, temp;
        for (int i = 0; i < steps; ++i){
            prev = 0;
            for (int j = 0; j < arrLen - 1; ++j){
                temp = dp[j];
                dp[j] = (((dp[j] + prev) % m) + dp[j + 1]) % m;
                prev = temp;
            }
            dp[arrLen - 1] = (prev + dp[arrLen - 1]) % m;
        }
        return dp[0];
    }
};
