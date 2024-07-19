import heapq as hq
from collections import defaultdict

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        rEdgeList = defaultdict(list)
        bEdgeList = defaultdict(list)
        for u, v in redEdges:
            rEdgeList[u].append(v)
        for u, v in blueEdges:
            bEdgeList[u].append(v)
        rDist = [-1] * n
        bDist = [-1] * n
        h = [(0, 0, False), (0, 0, True)]
        hq.heapify(h)
        while len(h) != 0:
            d, node, isRed = hq.heappop(h)
            if (rDist if isRed else bDist)[node] != -1:
                continue
            (rDist if isRed else bDist)[node] = d
            if isRed:
                for v in bEdgeList[node]:
                    if bDist[v] == -1:
                        hq.heappush(h, (d + 1, v, False))
            else:
                for v in rEdgeList[node]:
                    if rDist[v] == -1:
                        hq.heappush(h, (d + 1, v, True))
        res = [-1] * n
        for i in range(n):
            if rDist[i] == -1:
                res[i] = bDist[i]
            elif bDist[i] == -1:
                res[i] = rDist[i]
            else:
                res[i] = min(rDist[i], bDist[i])
        return res
