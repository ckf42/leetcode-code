from collections import defaultdict, deque

class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        edgeList = defaultdict(list)
        for e in edges:
            edgeList[e[0]].append(e[1])
            edgeList[e[1]].append(e[0])
        rt = next(i for i in range(n) if len(edgeList[i]) == 1)
        res = [0] * n
        res[rt] = 0
        parent = [None] * n
        parent[rt] = rt
        q = deque(((rt, rt, 0),))
        while len(q) != 0:
            node, par, lev = q.popleft()
            parent[node] = par
            res[rt] += lev
            for nb in edgeList[node]:
                if parent[nb] is None:
                    q.append((nb, node, lev + 1))
        subtreeSize = [1] * n
        def getSubtreeSize(node):
            for nb in edgeList[node]:
                if nb == parent[node]:
                    continue
                subtreeSize[node] += getSubtreeSize(nb)
            return subtreeSize[node]
        getSubtreeSize(rt)
        q.append(rt)
        while len(q) != 0:
            node = q.pop()
            for nb in edgeList[node]:
                if res[nb] != 0:
                    continue
                res[nb] = res[node] - subtreeSize[nb] * 2 + n
                q.append(nb)
        return res
