from bisect import bisect_left

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        memo = [0] * (n + 1)
        for i in range(n):
            memo[i + 1] = min(
                memo[i] + costs[0],
                memo[bisect_left(days, days[i] - 6, hi=i)] + costs[1],
                memo[bisect_left(days, days[i] - 29, hi=i)] + costs[2]
            )
        return memo[n]
