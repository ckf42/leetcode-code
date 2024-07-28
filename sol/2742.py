class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        minCost = [float('inf')] * (n + 1)
        minCost[0] = 0
        for i in range(n):
            for w in range(n, 0, -1):
                minCost[w] = min(minCost[w], minCost[max(w - time[i] - 1, 0)] + cost[i])
        return minCost[n]
