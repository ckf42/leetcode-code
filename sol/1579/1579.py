class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        edgeTypes = [list() for _ in range(4)]
        for i, e in enumerate(edges):
            edgeTypes[e[0]].append(i)
        aParent = list(range(n + 1))
        bParent = list(range(n + 1))
        aCompSize = [1] * (n + 1)
        bCompSize = [1] * (n + 1)
        def getParent(x, pArr):
            while pArr[x] != x:
                x, pArr[x] = pArr[x], pArr[pArr[x]]
            return x
        def sameGroup(x, y, pArr):
            return getParent(x, pArr) == getParent(y, pArr)
        def unionComp(a, b, pArr, sArr):
            a = getParent(a, pArr)
            b = getParent(b, pArr)
            if a == b:
                return
            if sArr[a] < sArr[b]:
                a, b = b, a
            pArr[b] = a
            sArr[a] += sArr[b]
        chosenEdges = 0
        for i in edgeTypes[3]:
            _, x, y = edges[i]
            if sameGroup(x, y, aParent) and sameGroup(x, y, bParent):
                continue
            chosenEdges += 1
            unionComp(x, y, aParent, aCompSize)
            unionComp(x, y, bParent, bCompSize)
        if aCompSize[getParent(1, aParent)] != n:
            for i in edgeTypes[1]:
                _, x, y = edges[i]
                if sameGroup(x, y, aParent):
                    continue
                chosenEdges += 1
                unionComp(x, y, aParent, aCompSize)
        if aCompSize[getParent(1, aParent)] != n:
            return -1
        if bCompSize[getParent(1, bParent)] != n:
            for i in edgeTypes[2]:
                _, x, y = edges[i]
                if sameGroup(x, y, bParent):
                    continue
                chosenEdges += 1
                unionComp(x, y, bParent, bCompSize)
        if bCompSize[getParent(1, bParent)] != n:
            return -1
        else:
            return len(edges) - chosenEdges

