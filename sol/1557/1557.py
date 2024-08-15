class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        arr = [True] * n
        for e in edges:
            arr[e[1]] = False
        for i in range(n):
            if arr[i]:
                yield i
