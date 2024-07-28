from collections import defaultdict

class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        hori = defaultdict(int)
        vert = defaultdict(int)
        diag1 = defaultdict(int)
        diag2 = defaultdict(int)
        lamps = set(tuple(c) for c in lamps)
        for i, j in lamps:
            hori[i] += 1
            vert[j] += 1
            diag1[i - j] += 1
            diag2[i + j] += 1
        res = []
        for i, j in queries:
            res.append(
                1
                if hori[i] != 0
                    or vert[j] != 0
                    or diag1[i - j] != 0
                    or diag2[i + j] != 0
                else 0
            )
            for ii in range(max(0, i - 1), min(n, i + 2)):
                for jj in range(max(0, j - 1), min(n, j + 2)):
                    if (ii, jj) in lamps:
                        lamps.remove((ii, jj))
                        hori[ii] -= 1
                        vert[jj] -= 1
                        diag1[ii - jj] -= 1
                        diag2[ii + jj] -= 1
        return res
