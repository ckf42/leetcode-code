struct Solution {
    int longestPalindromeSubseq(const string &s) {
        vector<int> dp(s.size(), 0);
        int bottomleft, temp;
        dp[0] = 1;
        for (int j = 1; j < s.size(); ++j){
            bottomleft = dp[j];
            dp[j] = 1;
            for (int i = j - 1; i >= 0; --i){
                temp = bottomleft;
                bottomleft = dp[i];
                dp[i] = (s[i] == s[j] ? 2 + temp : max(dp[i], dp[i + 1]));
            }
        }
        return dp[0];
    }
};
