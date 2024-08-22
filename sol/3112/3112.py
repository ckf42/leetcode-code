import heapq as hq

class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        res = [-1] * n
        edgeList = [list() for _ in range(n)]
        for u, v, w in edges:
            edgeList[u].append((v, w))
            edgeList[v].append((u, w))
        h = [(0, 0)]
        while len(h) != 0:
            t, node = hq.heappop(h)
            if res[node] != -1:
                continue
            res[node] = t
            for nb, w in edgeList[node]:
                if res[nb] == -1 and disappear[nb] > (tt := w + t):
                    hq.heappush(h, (tt, nb))
        return res
