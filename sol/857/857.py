import heapq as hq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)
        data = sorted(((wage[i] / quality[i], quality[i]) for i in range(n)))
        topRatio = data[k - 1][0]
        totQual = sum(x[1] for x in data[:k])
        minCost = topRatio * totQual
        h = [-x[1] for x in data[:k]]
        hq.heapify(h)
        for r, q in data[k:]:
            totQual += h[0] + q
            topRatio = r
            hq.heapreplace(h, -q)
            minCost = min(minCost, totQual * topRatio)
        return minCost
