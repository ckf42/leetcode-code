class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        parents = list(range(n))
        sizes = [1] * n

        def getParent(i):
            while parents[i] != i:
                i, parents[i] = parents[i], parents[parents[i]]
            return i
        
        def union(i, j):
            i = getParent(i)
            j = getParent(j)
            if i == j:
                return
            if sizes[i] < sizes[j]:
                i, j = j, i
            parents[j] = i
            sizes[i] += sizes[j]
        
        for e in edges:
            union(e[0], e[1])
        return getParent(source) == getParent(destination)
