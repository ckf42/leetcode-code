class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n))
        size = [1] * n
        def getParent(x):
            while parent[x] != x:
                x, parent[x] = parent[x], parent[parent[x]]
            return x
        def union(x, y):
            x = getParent(x)
            y = getParent(y)
            if x == y:
                return
            if size[x] < size[y]:
                x, y = y, x
            parent[y] = x
            size[x] += size[y]
        for i, j in edges:
            union(i, j)
        res = 0
        prefix = 0
        for c in (size[x] for x in frozenset(getParent(i) for i in range(n))):
            res += prefix * c
            prefix += c
        return res
