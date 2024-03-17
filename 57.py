import bisect

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        l = bisect.bisect_left(intervals, newInterval[0], key=lambda itv: itv[1])
        if l < len(intervals):
            newInterval[0] = min(newInterval[0], intervals[l][0])
        r = bisect.bisect_right(intervals, newInterval[1], key=lambda itv: itv[0])
        if r > 0:
            newInterval[1] = max(newInterval[1], intervals[r - 1][1])
        intervals[l:r] = [newInterval]
        return intervals
