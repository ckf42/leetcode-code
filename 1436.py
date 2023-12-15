from collections import defaultdict

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        cities = set()
        outDeg = defaultdict(int)
        for a, b in paths:
            cities.update((a, b))
            outDeg[a] += 1
        return next(c for c in cities if outDeg[c] == 0)
