#include <algorithm>

struct Solution {
    int longestCommonSubsequence(const string &text1, const string &text2) {
        vector<int> dp(text2.size(), 0);
        dp[0] = (text1[0] == text2[0] ? 1 : 0);
        for (int j = 1; j < text2.size(); ++j){
            dp[j] = (text1[0] == text2[j] ? 1 : dp[j - 1]);
        }
        int topleft, temp;
        for (int i = 1; i < text1.size(); ++i){
            topleft = dp[0];
            dp[0] = (text1[i] == text2[0] ? 1 : dp[0]);
            for (int j = 1; j < text2.size(); ++j){
                temp = topleft;
                topleft = dp[j];
                dp[j] = (text1[i] == text2[j] ? 1 + temp : max(dp[j - 1], dp[j]));
            }
        }
        return dp.back();
    }
};
