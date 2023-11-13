from itertools import groupby

class Solution:
    def countHomogenous(self, s: str) -> int:
        m = int(1e9) + 7
        res = 0
        for g in groupby(s):
            n = len(tuple(g[1]))
            res += n * (n + 1) // 2
        return res % m

