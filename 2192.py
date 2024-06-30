from collections import defaultdict

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        edgeList = defaultdict(list)
        indeg = [0] * n
        for a, b in edges:
            edgeList[a].append(b)
            indeg[b] += 1
        resSet = [set() for _ in range(n)]
        lvl = [i for i in range(n) if indeg[i] == 0]
        while len(lvl) != 0:
            newLvl = []
            for x in lvl:
                indeg[x] = -1
                for nb in edgeList[x]:
                    indeg[nb] -= 1
                    resSet[nb].update(resSet[x])
                    resSet[nb].add(x)
                    if indeg[nb] == 0:
                        newLvl.append(nb)
            lvl = newLvl
        return [sorted(s) for s in resSet]
