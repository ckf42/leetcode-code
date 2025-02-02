class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] <= 0:
                    continue
                total = 0
                buff = [(i, j)]
                while len(buff) != 0:
                    x, y = buff.pop()
                    if grid[x][y] <= 0:
                        continue
                    total += grid[x][y]
                    grid[x][y] = 0
                    for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                        xx = x + dx
                        yy = y + dy
                        if 0 <= xx < m and 0 <= yy < n and grid[xx][yy] > 0:
                            buff.append((xx, yy))
                res = max(res, total)
        return res
