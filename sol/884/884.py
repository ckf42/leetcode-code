from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        c1 = Counter(s1.split())
        c2 = Counter(s2.split())
        res = []
        for k, v in c1.items():
            if v == 1 and k not in c2:
                res.append(k)
        for k, v in c2.items():
            if v == 1 and k not in c1:
                res.append(k)
        return res
