class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        m = 10 ** 9 + 7
        cand = [j for i in range(1, n + 1) if (j := i ** x) <= n]
        l = len(cand)
        memo = [0 for _ in range(n + 1)]
        memo[0] = 1
        for i in range(l):
            for nn in range(n, cand[i] - 1, -1):
                memo[nn] = (memo[nn] + memo[nn - cand[i]]) % m
        return memo[n]
