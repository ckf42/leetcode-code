
import heapq as hq
from collections import defaultdict

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edgeList = defaultdict(list)
        for u, v, w in times:
            edgeList[u].append((v, w))
        reachTime = [-1] * (n + 1)
        h = [(0, k)]
        while len(h) != 0:
            t, u = hq.heappop(h)
            if reachTime[u] != -1:
                continue
            reachTime[u] = t
            for v, w in edgeList[u]:
                if reachTime[v] == -1:
                    hq.heappush(h, (t + w, v))
        return max(reachTime[1:]) if all(t != -1 for t in reachTime[1:]) else -1

