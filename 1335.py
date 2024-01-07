class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        dp = [-1] * n
        mv = -1
        for j in range(n):
            mv = max(mv, jobDifficulty[j])
            dp[j] = mv
        for dd in range(2, d + 1):
            for j in range(n - 1, dd - 1 - 1, -1):
                mv = jobDifficulty[j]
                dp[j] = mv + dp[j - 1]
                for e in range(j - 2, dd - 2 - 1, -1):
                    mv = max(mv, jobDifficulty[e + 1])
                    dp[j] = min(dp[j], mv + dp[e])
        return dp[-1]

