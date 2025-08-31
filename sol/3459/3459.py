from functools import cache

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ds = [(-1, -1), (-1, 1), (1, 1), (1, -1)]
        @cache
        def comp(x, y, d, canTurn):
            if not (0 <= x < m and 0 <= y < n):
                return 0
            res = 0
            target = 0 if grid[x][y] == 2 else 2
            xx, yy = x + ds[d][0], y + ds[d][1]
            if 0 <= xx < m and 0 <= yy < n and grid[xx][yy] == target:
                res = max(res, comp(xx, yy, d, canTurn))
            if canTurn:
                d = (d + 1) & 3
                xx, yy = x + ds[d][0], y + ds[d][1]
                if 0 <= xx < m and 0 <= yy < n and grid[xx][yy] == target:
                    res = max(res, comp(xx, yy, d, False))
            return res + 1
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 1:
                    continue
                for d in range(4):
                    match d:
                        case 0:
                            lim = i + 1
                        case 1:
                            lim = n - j
                        case 2:
                            lim = m - i
                        case 3:
                            lim = j + 1
                    if res >= lim:
                        continue
                    res = max(res, comp(i, j, d, True))
        return res
        
