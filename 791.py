from collections import defaultdict

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        ruled = frozenset(order)
        counter = defaultdict(int)
        l = list()
        for c in s:
            if c in ruled:
                counter[c] += 1
            else:
                l.append(c)
        for c in order:
            l.append(c * counter[c])
        return "".join(l)
