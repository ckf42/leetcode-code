from functools import cache

@cache
def binom(n, r):
    if r == 0 or r == n:
        return 1
    return (binom(n - 1, r - 1) + binom(n - 1, r)) % (10 ** 9 + 7)

class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        M = 10 ** 9 + 7
        n = len(nums)
        @cache
        def solve(remainSpots, remainBits, idxToChoose, lastBits):
            if remainSpots == 0:
                return 1 if remainBits == lastBits.bit_count() else 0
            if idxToChoose >= n:
                return 0
            if remainBits > lastBits.bit_count() + remainSpots:
                return 0
            res = 0
            bitToCommit = lastBits & 1
            for mul in range(0, remainSpots + 1):
                newBits = (lastBits >> 1) + mul
                res = (
                    res
                    + binom(remainSpots, mul)
                        * pow(nums[idxToChoose], mul, M)
                        * solve(remainSpots - mul, remainBits - bitToCommit, idxToChoose + 1, newBits)
                ) % M
            return res
        return solve(m, k, 0, 0)
