class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(s) < len(t):
            return 0
        dp = [0] * len(s)
        dp[0] = 1 if s[0] == t[0] else 0
        for i in range(1, len(s)):
            dp[i] = dp[i - 1] + (1 if s[i] == t[0] else 0)
        for j in range(1, len(t)):
            topleft = dp[j]
            dp[j] = dp[j - 1] if s[j] == t[j] else 0
            for i in range(j + 1, len(s)):
                topleft, dp[i] = dp[i], dp[i - 1] + (topleft if s[i] == t[j] else 0)
        return dp[-1]

