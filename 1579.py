class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        edgeList = [list() for _ in range(4)]
        for t, a, b in edges:
            edgeList[t].append((a, b))
        parent = list(range(n + 1))
        compSize = [1] * (n + 1)
        def getParent(x):
            while parent[x] != x:
                x, parent[x] = parent[x], parent[parent[x]]
            return x
        def unionComp(a, b):
            a = getParent(a)
            b = getParent(b)
            if a == b:
                return
            if compSize[a] < compSize[b]:
                a, b = b, a
            parent[b] = a
            compSize[a] += compSize[b]
        chosen = []
        for i, e in enumerate(edgeList[3]):
            a, b = e
            if getParent(a) == getParent(b):
                continue
            chosen.append((3, i))
            unionComp(a, b)
        for i, e in enumerate(edgeList[1]):
            a, b = e
            if getParent(a) == getParent(b):
                continue
            chosen.append((1, i))
            unionComp(a, b)
        if compSize[getParent(1)] != n:
            return -1
        parent = list(range(n + 1))
        compSize = [1] * (n + 1)
        for t, i in chosen:
            if t == 3:
                unionComp(edgeList[3][i][0], edgeList[3][i][1])
        for i, e in enumerate(edgeList[3]):
            a, b = e
            if getParent(a) == getParent(b):
                continue
            chosen.append((3, i))
            unionComp(a, b)
        for i, e in enumerate(edgeList[2]):
            a, b = e
            if getParent(a) == getParent(b):
                continue
            chosen.append((2, i))
            unionComp(a, b)
        if compSize[getParent(1)] != n:
            return -1
        else:
            return len(edges) - len(chosen)
