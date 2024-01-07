from functools import cache

class Solution:
    M = int(1e9) + 7

    @cache
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        if target < 0:
            return 0
        if target == 0:
            return 1 if n == 0 else 0
        if target > k * n:
            return 0
        if target == k * n:
            return 1
        res = 0
        for f in range(1, k + 1):
            res = (res + self.numRollsToTarget(n - 1, k, target - f)) % self.M
        return res
