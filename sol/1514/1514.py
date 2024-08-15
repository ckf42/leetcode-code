import heapq as hq
import math

from collections import defaultdict

class Solution:
    def maxProbability(self,
            n: int, edges: List[List[int]], succProb: List[float],
            start_node: int, end_node: int) -> float:
        succProb = [-(float('inf') if p == 0 else math.log(p)) for p in succProb]
        edgeList = defaultdict(list)
        for (a, b), lp in zip(edges, succProb):
            edgeList[a].append((b, lp))
            edgeList[b].append((a, lp))
        dist = [-1] * n
        h = [(0, start_node)]
        while len(h) != 0:
            d, node = hq.heappop(h)
            if dist[node] != -1:
                continue
            dist[node] = d
            if node == end_node:
                return math.exp(-d)
            for v, lp in edgeList[node]:
                if dist[v] == -1:
                    hq.heappush(h, (d + lp, v))
        return 0.0
