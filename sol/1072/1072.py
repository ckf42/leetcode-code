from collections import Counter

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        d = Counter()
        for r in matrix:
            if r[0] == 0:
                d[tuple(r)] += 1
            else:
                d[tuple(1 ^ x for x in r)] += 1
        return max(d.values())
