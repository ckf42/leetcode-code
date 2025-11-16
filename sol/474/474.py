from functools import cache

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        l = len(strs)
        ones = [0] * l
        zeros = [0] * l
        for i, s in enumerate(strs):
            ones[i] = s.count('1')
            zeros[i] = len(s) - ones[i]
        @cache
        def dp(i, a, b):
            if i == l:
                return 0
            res = dp(i + 1, a, b)
            if zeros[i] <= a and ones[i] <= b:
                res = max(res, dp(i + 1, a - zeros[i], b - ones[i]) + 1)
            return res
        return dp(0, m, n)
