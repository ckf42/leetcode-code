from functools import cache

class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        res = n * m
        @cache
        def minToCover(a, b, c, d):  # [a, b] x [c, d]
            x0 = b + 1
            x1 = a - 1
            y0 = d + 1
            y1 = c - 1
            for i in range(a, b + 1):
                for j in range(c, d + 1):
                    if grid[i][j]:
                        x0 = min(x0, i)
                        x1 = i
                        y0 = min(y0, j)
                        y1 = max(y1, j)
            print(a, b, c, d, (x1 - x0 + 1) * (y1 - y0 + 1))
            return (x1 - x0 + 1) * (y1 - y0 + 1)
        for i1 in range(n - 1):
            a1 = minToCover(0, i1, 0, m - 1)
            a2 = minToCover(i1 + 1, n - 1, 0, m - 1)
            if a1 == 0 or a2 == 0:
                continue
            if a1 < res:
                for i2 in range(i1 + 1, n - 1):
                    res = min(res, a1 + minToCover(i1 + 1, i2, 0, m - 1) + minToCover(i2 + 1, n - 1, 0, m - 1))
                for j in range(0, m - 1):
                    res = min(res, a1 + minToCover(i1 + 1, n - 1, 0, j) + minToCover(i1 + 1, n - 1, j + 1, m - 1))
            if a2 < res:
                for j in range(0, m - 1):
                    res = min(res, a2 + minToCover(0, i1, 0, j) + minToCover(0, i1, j + 1, m - 1))
        for j1 in range(m - 1):
            a1 = minToCover(0, n - 1, 0, j1)
            a2 = minToCover(0, n - 1, j1 + 1, m - 1)
            if a1 == 0 or a2 == 0:
                continue
            if a1 < res:
                for j2 in range(j1 + 1, m - 1):
                    res = min(res, a1 + minToCover(0, n - 1, j1 + 1, j2) + minToCover(0, n - 1, j2 + 1, m - 1))
                for i in range(0, n - 1):
                    res = min(res, a1 + minToCover(0, i, j1 + 1, m - 1) + minToCover(i + 1, n - 1, j1 + 1, m - 1))
            if a2 < res:
                for i in range(0, n - 1):
                    res = min(res, a2 + minToCover(0, i, 0, j1) + minToCover(i + 1, n - 1, 0, j1))
        return res
