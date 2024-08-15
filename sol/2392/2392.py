from collections import defaultdict, deque

class Solution:
    def topoSort(self, k: int, cond: list[list[int]]) -> list[int]:
        res = []
        edgeList = defaultdict(list)
        indeg = defaultdict(int)
        for u, v in cond:
            edgeList[u].append(v)
            indeg[v] += 1
        q = deque([i for i in range(1, k + 1) if indeg[i] == 0])
        while len(q) != 0:
            node = q.popleft()
            res.append(node)
            for v in edgeList[node]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)
        if len(res) == k:
            return res
        return []

    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        rowOrder = self.topoSort(k, rowConditions)
        if len(rowOrder) == 0:
            return []
        colOrder = self.topoSort(k, colConditions)
        if len(colOrder) == 0:
            return []
        res = [[0] * k for _ in range(k)]
        ridx = {x: i for i, x in enumerate(rowOrder)}
        cidx = {x: i for i, x in enumerate(colOrder)}
        for i in range(1, k + 1):
            res[ridx[i]][cidx[i]] = i
        return res
