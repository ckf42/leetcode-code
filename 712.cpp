struct Solution {
    int minimumDeleteSum(const string &s1, const string &s2) {
        vector<int> dp(s2.size(), 0);
        int prefixSum = s2[0], topleft, temp;
        dp[0] = (s1[0] == s2[0] ? 0 : s1[0] + s2[0]);
        for (int j = 1; j < s2.size(); ++j){
            dp[j] = (s1[0] == s2[j] ? prefixSum : dp[j - 1] + s2[j]);
            prefixSum += s2[j];
        }
        prefixSum = s1[0];
        for (int i = 1; i < s1.size(); ++i){
            topleft = dp[0];
            dp[0] = (s1[i] == s2[0] ? prefixSum : dp[0] + s1[i]);
            prefixSum += s1[i];
            for (int j = 1; j < s2.size(); ++j){
                temp = topleft;
                topleft = dp[j];
                dp[j] = (s1[i] == s2[j] ? temp : min(dp[j - 1] + s2[j], dp[j] + s1[i]));
            }
        }
        return dp.back();
    }
};
