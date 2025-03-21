class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        parent = list(range(n))
        size = [1] * n
        cost = [0xfffff] * n
        def getPar(x):
            while parent[x] != x:
                x, parent[x] = parent[x], parent[parent[x]]
            return x
        def unionGp(x, y, w):
            x = getPar(x)
            y = getPar(y)
            cost[x] &= w
            if x == y:
                return
            if size[x] < size[y]:
                x, y = y, x
            parent[y] = x
            size[x] += size[y]
            cost[x] &= cost[y]
        for u, v, w in edges:
            unionGp(u, v, w)
        res = []
        for s, t in query:
            s = getPar(s)
            t = getPar(t)
            if s != t:
                res.append(-1)
            else:
                res.append(cost[s])
        return res
            
