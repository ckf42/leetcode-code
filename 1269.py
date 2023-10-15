class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        m = int(1e9) + 7
        arrLen = min(arrLen, steps // 2 + 1)
        if arrLen == 1:
            return 1
        dp = [0] * arrLen
        dp[0] = 1
        for i in range(steps):
            prev = 0
            for j in range(arrLen - 1):
                dp[j], prev = (prev + dp[j] + dp[j + 1]) % m, dp[j]
            dp[arrLen - 1] = (prev + dp[arrLen - 1]) % m
        return dp[0]

