from collections import Counter

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cs = Counter(s)
        ct = Counter(t)
        res = 0
        for c, v in cs.items():
            val = v - ct[c]
            if val > 0:
                res += val
        return res
