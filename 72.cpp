struct Solution {
    int minDistance(const string &word1, const string &word2) {
        if (word1.size() == 0 || word2.size() == 0){
            return word1.size() + word2.size();
        }
        vector<int> dp(word2.size(), 0);
        dp[0] = (word1[0] == word2[0] ? 0 : 1);
        for (int j = 1; j < word2.size(); ++j){
            dp[j] = (word1[0] == word2[j] ? j : 1 + min(j, dp[j - 1]));
        }
        int topleft, temp;
        for (int i = 1; i < word1.size(); ++i){
            topleft = dp[0];
            dp[0] = (word1[i] == word2[0] ? i : 1 + min(i, topleft));
            for (int j = 1; j < word2.size(); ++j){
                temp = topleft;
                topleft = dp[j];
                dp[j] = (word1[i] == word2[j] ? temp : 1 + min(temp, min(dp[j - 1], dp[j])));
            }
        }
        return dp.back();
    }
};
