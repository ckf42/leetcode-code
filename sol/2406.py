import heapq as hq

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda itv: itv[0])
        h = []
        res = 0
        for itv in intervals:
            if len(h) == 0 or h[0] >= itv[0]:
                res += 1
                hq.heappush(h, itv[1])
            else:
                hq.heapreplace(h, itv[1])
        return res
