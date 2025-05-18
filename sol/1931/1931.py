from collections import defaultdict

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        M = 10 ** 9 + 7
        def genCol(prev, remainLen):
            if remainLen == 0:
                yield tuple()
                return
            for i in (0, 1, 2):
                if i == prev:
                    continue
                for remainPart in genCol(i, remainLen - 1):
                    yield (i,) + remainPart
        allCols = list(genCol(-1, m))
        l = len(allCols)
        def canAdj(i, j):
            return all(a != b for a, b in zip(allCols[i], allCols[j]))
        adj = defaultdict(list)
        for i in range(l):
            for j in range(i + 1, l):
                if canAdj(i, j):
                    adj[i].append(j)
                    adj[j].append(i)
        vec = [1] * l
        for _ in range(2, n + 1):
            vec = [
                sum(vec[j] for j in adj[i]) % M
                for i in range(l)
            ]
        return sum(vec) % M
