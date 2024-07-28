class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = [0] * len(s)
        dp[0] = 1
        for j in range(1, len(s)):
            bottomleft = dp[j]
            dp[j] = 1
            for i in range(j - 1, -1, -1):
                bottomleft, dp[i] = dp[i], (2 + bottomleft if s[i] == s[j] else max(dp[i], dp[i + 1]))
        return dp[0]


