from itertools import combinations

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        h = [set() for _ in range(26)]
        for w in ideas:
            h[ord(w[0]) - ord('a')].add(w[1:])
        return sum(len(s1.difference(s2)) * len(s2.difference(s1)) for s1, s2 in combinations(h, 2)) * 2
