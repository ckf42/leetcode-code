struct Solution {
    long long mostPoints(const vector<vector<int>>& questions) {
        const int n = questions.size();
        int b;
        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i){
            b = questions[i][1];
            dp[i] = max(dp[i + 1],
                        questions[i][0] + (i + b + 1 < n ? dp[i + b + 1] : 0));
        }
        return dp[0];
    }
};
