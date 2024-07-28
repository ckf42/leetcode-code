struct Solution {
    int coinChange(const vector<int>& coins, int amount) {
        if (amount == 0){
            return 0;
        }
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int c: coins){
            if (c > amount){
                continue;
            }
            if (c == amount){
                return 1;
            }
            dp[c] = 1;
            for (int i = c + 1; i <= amount; ++i){
                if (dp[i - c] == -1){
                    continue;
                }
                if (dp[i] == -1 || dp[i - c] + 1 < dp[i]){
                    dp[i] = dp[i - c] + 1;
                }
            }
        }
        return dp[amount];
    }
};
