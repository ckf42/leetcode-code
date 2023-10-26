class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [0] * len(text2)
        dp[0] = 1 if text1[0] == text2[0] else 0
        for j in range(1, len(text2)):
            dp[j] = 1 if text1[0] == text2[j] else dp[j - 1]
        for i in range(1, len(text1)):
            topleft = dp[0]
            dp[0] = 1 if text1[i] == text2[0] else dp[0]
            for j in range(1, len(text2)):
                topleft, dp[j] = dp[j], (1 + topleft if text1[i] == text2[j] else max(dp[j - 1], dp[j]))
        return dp[-1]
