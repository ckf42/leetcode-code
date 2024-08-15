from functools import cache

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        postSum = [0] * (n + 1)
        postSum[n - 1] = piles[n - 1]
        for i in range(n - 2, -1, -1):
            postSum[i] = postSum[i + 1] + piles[i]
        @cache
        def dp(i, m):
            if i >= n:
                return 0
            if i + m >= n:
                return postSum[i]
            return max((
                postSum[i] - dp(i + x, max(m, x))
                for x in range(1, min(m * 2, n - i) + 1)
            ))
        return dp(0, 1)
