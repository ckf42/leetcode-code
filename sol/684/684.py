class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parents = list(range(1001))
        sizes = [1] * 1001
        def getPar(x):
            while x != parents[x]:
                x, parents[x] = parents[x], parents[parents[x]]
            return x
        def unionGp(x, y):
            x = getPar(x)
            y = getPar(y)
            if x == y:
                return
            if sizes[x] < sizes[y]:
                x, y = y, x
            parents[y] = x
            sizes[x] += sizes[y]
        for a, b in edges:
            x = getPar(a)
            y = getPar(b)
            if x == y:
                return [a, b]
            unionGp(x, y)
        return [-1, -1]
