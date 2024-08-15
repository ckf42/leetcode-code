class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda itv: itv[1])
        res = 0
        pos = points[0][0] - 1
        for itv in points:
            if pos < itv[0]:
                pos = itv[1]
                res += 1
        return res
