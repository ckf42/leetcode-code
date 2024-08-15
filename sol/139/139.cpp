struct Solution {
    bool wordBreak(const string &s, const vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp.back() = true;
        for (int i = s.size() - 1; i >= 0; --i){
            for (const string &w : wordDict){
                if (i + w.size() <= s.size() && s.substr(i, w.size()) == w && dp[i + w.size()]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
