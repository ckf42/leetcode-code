class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        dp = [0] * len(s2)
        dp[0] = 0 if s1[0] == s2[0] else (ord(s1[0]) + ord(s2[0]))
        prefixSum = ord(s2[0])
        for j in range(1, len(s2)):
            dp[j] = prefixSum if s1[0] == s2[j] else (dp[j - 1] + ord(s2[j]))
            prefixSum += ord(s2[j])
        prefixSum = ord(s1[0])
        for i in range(1, len(s1)):
            topleft = dp[0]
            dp[0] = prefixSum if s1[i] == s2[0] else (dp[0] + ord(s1[i]))
            prefixSum += ord(s1[i])
            for j in range(1, len(s2)):
                topleft, dp[j] = dp[j], (topleft if s1[i] == s2[j] else min(dp[j - 1] + ord(s2[j]), dp[j] + ord(s1[i])))
        return dp[-1]
