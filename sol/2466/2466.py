class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        M = 10 ** 9 + 7
        memo = [0] * (high + 1)
        memo[0] = 1
        res = 0
        for i in range(1, high + 1):
            if i >= zero:
                memo[i] = (memo[i] + memo[i - zero]) % M
            if i >= one:
                memo[i] = (memo[i] + memo[i - one]) % M
            if i >= low:
                res = (res + memo[i]) % M
        return res
