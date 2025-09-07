class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort(key=lambda pt: (pt[0], -pt[1]))
        miny = min(pt[1] for pt in points)
        res = 0
        for i in range(n):
            x, y = points[i]
            bd = miny - 1
            for j in range(i + 1, n):
                if y >= points[j][1] > bd:
                    res += 1
                    bd = points[j][1]
        return res
