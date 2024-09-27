import heapq as hq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        def d(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        notReached = set(range(1, n))
        h = [(d(points[0], points[i]), i) for i in range(1, n)]
        hq.heapify(h)
        cost = 0
        for _ in range(n - 1):
            while h[0][1] not in notReached:
                hq.heappop(h)
            w, i = hq.heappop(h)
            notReached.remove(i)
            cost += w
            for j in notReached:
                hq.heappush(h, (d(points[i], points[j]), j))
        return cost
