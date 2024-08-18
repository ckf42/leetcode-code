class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m = len(points)
        n = len(points[0])
        buff = [0] * n
        for i in range(1, m):
            opt = points[i - 1][0]
            buff[0] = opt + points[i][0]
            for j in range(1, n):
                opt = max(opt - 1, points[i - 1][j])
                buff[j] = opt + points[i][j]
            opt = 0
            points[i][n - 1] = buff[n - 1]
            for j in range(n - 2, -1, -1):
                opt = max(opt, points[i - 1][j + 1]) - 1
                points[i][j] = max(buff[j], opt + points[i][j])
        return max(points[m - 1])
