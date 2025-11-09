import heapq as hq

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        par = list(range(c + 1))
        size = [1] * (c + 1)
        def getPar(x):
            while par[x] != x:
                x, par[x] = par[x], par[par[x]]
            return x
        def unionGp(x, y):
            x = getPar(x)
            y = getPar(y)
            if x == y:
                return
            if size[x] < size[y]:
                x, y = y, x
            par[y] = x
            size[x] += y
        for u, v in connections:
            unionGp(u, v)
        hs = [list() for _ in range(c + 1)]
        isOn = [True] * (c + 1)
        for i in range(1, c + 1):
            hq.heappush(hs[getPar(i)], i)
        res = []
        for a, b in queries:
            if a == 2:
                isOn[b] = False
            elif isOn[b]:
                res.append(b)
            else:
                p = getPar(b)
                while len(hs[p]) != 0 and not isOn[hs[p][0]]:
                    hq.heappop(hs[p])
                res.append(-1 if len(hs[p]) == 0 else hs[p][0])
        return res

