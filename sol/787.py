import heapq as hq
from collections import defaultdict

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        edges = defaultdict(dict)
        for s, e, p in flights:
            edges[s][e] = p
        h = [(0, src, 0)]
        visited = dict()
        while len(h) != 0:
            cost, state, stops = hq.heappop(h)
            if state == dst:
                return cost
            if stops >= visited.get(state, k + 1):
                continue
            visited[state] = stops
            if stops == k + 1:
                continue
            for n, p in edges[state].items():
                hq.heappush(h, (cost + p, n, stops + 1))
        return -1

