from bisect import bisect

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # idea from https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/4515229/optimized-job-scheduling-a-dynamic-programming-approach
        n = len(startTime)
        sortedJobIdx = sorted(range(n), key=lambda i: endTime[i])
        memo = [0] * n
        memo[0] = profit[sortedJobIdx[0]]
        for jobIdx in range(1, n):
            s = startTime[sortedJobIdx[jobIdx]]
            idx = bisect(range(n), s, hi=jobIdx, key=lambda i: endTime[sortedJobIdx[i]]) - 1
            memo[jobIdx] = max(memo[jobIdx - 1], memo[idx] + profit[sortedJobIdx[jobIdx]])
        return memo[-1]
