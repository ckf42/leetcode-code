class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indeg = [0] * n
        for a, b in edges:
            indeg[b] += 1
        res = -1
        for i, x in enumerate(indeg):
            if x == 0:
                if res == -1:
                    res = i
                else:
                    return -1
        return res
