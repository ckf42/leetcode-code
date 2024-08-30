import heapq as hq

from collections import defaultdict

class Solution:
    maxWeight = 2 * 10 ** 9
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        edgeList = defaultdict(list)
        modEdgeIndices = []
        for i, e in enumerate(edges):
            edgeList[e[0]].append((e[1], i))
            edgeList[e[1]].append((e[0], i))
            if e[2] == -1:
                modEdgeIndices.append(i)
        h = [(0, source)]
        minDist = [-1] * n
        while len(h) != 0:
            cost, node = hq.heappop(h)
            if minDist[node] != -1:
                continue
            minDist[node] = cost
            for nb, idx in edgeList[node]:
                if minDist[nb] == -1:
                    w = edges[idx][2]
                    if w == -1:
                        w = 1
                    hq.heappush(h, (cost + w, nb))
        if minDist[destination] == -1 or minDist[destination] > target:
            return []
        diff = target - minDist[destination]
        h = [(0, source)]
        dist = [-1] * n
        while len(h) != 0:
            cost, node = hq.heappop(h)
            if dist[node] != -1:
                continue
            dist[node] = cost
            if node == destination:
                break
            for nb, idx in edgeList[node]:
                if edges[idx][2] == -1:
                    edges[idx][2] = max(1, target - cost - (minDist[destination] - minDist[nb]))
                hq.heappush(h, (cost + edges[idx][2], nb))
        if dist[destination] != target:
            return []
        for idx in modEdgeIndices:
            if edges[idx][2] == -1:
                edges[idx][2] = self.maxWeight
        return edges
