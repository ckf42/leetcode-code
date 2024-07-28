class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len(word1) == 0 or len(word2) == 0:
            return len(word1) + len(word2)
        dp = [0] * len(word2)
        dp[0] = 0 if word1[0] == word2[0] else 1
        for j in range(1, len(word2)):
            dp[j] = j if word1[0] == word2[j] else (1 + min(dp[j - 1], j))
        for i in range(1, len(word1)):
            topleft = dp[0]
            dp[0] = i if word1[i] == word2[0] else (1 + min(dp[0], i))
            for j in range(1, len(word2)):
                topleft, dp[j] = dp[j], topleft if word1[i] == word2[j] else (1 + min(topleft, dp[j - 1], dp[j]))
        return dp[-1]
