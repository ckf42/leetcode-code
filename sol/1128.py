from collections import defaultdict

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        h = defaultdict(int)
        for dom in dominoes:
            a, b = dom
            if a > b:
                a, b = b, a
            h[a * 10 + b] += 1
        return sum(v * (v - 1) // 2 for v in h.values())
