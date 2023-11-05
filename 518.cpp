struct Solution {
    int change(int amount, const vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int c : coins){
            for (int j = c; j <= amount; ++j){
                dp[j] += dp[j - c];
            }
        }
        return dp.back();
    }
};
