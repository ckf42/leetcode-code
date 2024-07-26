import heapq as hq

from collections import defaultdict

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        edgeList = defaultdict(list)
        for u, v, w in edges:
            edgeList[u].append((v, w))
            edgeList[v].append((u, w))
        res = 0
        count = n
        for i in range(n):
            dist = [-1] * n
            h = [(0, i)]
            currCount = 0
            while len(h) != 0:
                d, node = hq.heappop(h)
                if dist[node] != -1:
                    continue
                dist[node] = d
                if d > distanceThreshold:
                    continue
                currCount += 1
                for v, w in edgeList[node]:
                    if dist[v] == -1:
                        hq.heappush(h, (d + w, v))
            if currCount <= count:
                res = i
                count = currCount
        return res
