import heapq as hq

from collections import defaultdict

class Solution:
    m = int(1e9) + 7
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        edgeList = defaultdict(list)
        for u, v, t in roads:
            edgeList[u].append((v, t))
            edgeList[v].append((u, t))
        dist = [-1] * n
        dist[0] = 0
        h = [(0, 0)]
        memo = [0] * n
        memo[0] = 1
        while len(h) != 0:
            d, node = hq.heappop(h)
            if dist[node] != -1 and dist[node] < d:
                continue
            for v, t in edgeList[node]:
                w = d + t
                if dist[v] == -1 or dist[v] > w:
                    dist[v] = w
                    memo[v] = memo[node]
                    hq.heappush(h, (w, v))
                elif dist[v] == w:
                    memo[v] = (memo[v] + memo[node]) % self.m
        return memo[n - 1]
