class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda pt: (pt[1], -pt[0]))
        res = 0
        n = len(points)
        for i in range(n):
            for j in range(i + 1, n):
                if points[i][0] < points[j][0]:
                    continue
                for k in range(i + 1, j):
                    if points[i][0] >= points[k][0] >= points[j][0]:
                        break
                else:
                    res += 1
        return res
