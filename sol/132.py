from functools import cache

class Solution:
    def minCut(self, s: str) -> int:
        @cache
        def ispal(i, j):
            if i >= j:
                return True
            return s[i] == s[j] and ispal(i + 1, j - 1)
        n = len(s)
        if ispal(0, n - 1):
            return 0
        memo = [n - 1] * n
        memo[0] = 0
        for i in range(1, n):
            if ispal(0, i):
                memo[i] = 0
                continue
            for j in range(i):
                if ispal(j + 1, i):
                    memo[i] = min(memo[i], memo[j] + 1)
        return memo[n - 1]
