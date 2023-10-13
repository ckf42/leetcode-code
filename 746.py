class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp0, dp1 = cost[0], cost[1]
        for i in range(2, len(cost)):
            dp0, dp1 = dp1, cost[i] + min(dp0, dp1)
        return min(dp0, dp1)
