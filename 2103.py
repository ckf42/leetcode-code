from collections import defaultdict

class Solution:
    def countPoints(self, rings: str) -> int:
        n = len(rings)
        d = defaultdict(int)
        for i in range(0, n, 2):
            d[rings[i + 1]] |= (1 if rings[i] == 'R' else (2 if rings[i] == 'B' else 4))
        return sum(v == 7 for v in d.values())
