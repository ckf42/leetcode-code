from itertools import groupby
from collections import defaultdict

class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        h = defaultdict(int)
        for c, part in groupby(s):
            l = len(tuple(part))
            for i in range(1, l + 1):
                h[(c, i)] += l - i + 1
        res = -1
        for k, v in h.items():
            if v >= 3:
                res = max(res, k[1])
        return res
