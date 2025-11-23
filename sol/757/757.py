class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        n = len(intervals)
        intervals.sort(key=lambda itv: (itv[1], -itv[0]))
        res = 2
        a = intervals[0][1] - 1
        b = intervals[0][1]
        for i in range(1, n):
            c, d = intervals[i]
            if c > b:
                res += 2
                a, b = d - 1, d
            elif c > a:
                res += 1
                a, b = b, d
        return res
