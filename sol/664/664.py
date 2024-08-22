from functools import cache

class Solution:
    def strangePrinter(self, s: str) -> int:
        gp = tuple(c for i, c in enumerate(s) if i == 0 or s[i] != s[i - 1])
        ngp = len(gp)
        @cache
        def dp(i, j):
            if i > j:
                return 0
            p = 1 + dp(i + 1, j)
            for k in range(i + 1, j + 1):
                if gp[k] == gp[i]:
                    p = min(
                        p,
                        dp(k + 1, j) + dp(i, k - 1)
                    )
            return p
        return dp(0, ngp - 1)
