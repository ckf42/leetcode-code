class Solution:
    DIRS = (
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0)
    )
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        islandSize = [0]
        islandId = [[0] * n for _ in range(n)]
        res = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] != 1:
                    continue
                buff = [(i, j)]
                count = 0
                while len(buff) != 0:
                    x, y = buff.pop()
                    if grid[x][y] != 1:
                        continue
                    grid[x][y] = 2
                    count += 1
                    for dx, dy in self.DIRS:
                        xx = x + dx
                        yy = y + dy
                        if 0 <= xx < n and 0 <= yy < n and grid[xx][yy] == 1:
                            buff.append((xx, yy))
                res = max(res, count)
                buff = [(i, j)]
                while len(buff) != 0:
                    x, y = buff.pop()
                    if grid[x][y] != 2:
                        continue
                    grid[x][y] = 3
                    islandId[x][y] = len(islandSize)
                    for dx, dy in self.DIRS:
                        xx = x + dx
                        yy = y + dy
                        if 0 <= xx < n and 0 <= yy < n and grid[xx][yy] == 2:
                            buff.append((xx, yy))
                islandSize.append(count)
        for i in range(n):
            for j in range(n):
                if grid[i][j] != 0:
                    continue
                nbGps = set()
                for di, dj in self.DIRS:
                    ii = i + di
                    jj = j + dj
                    if 0 <= ii < n and 0 <= jj < n:
                        nbGps.add(islandId[ii][jj])
                res = max(res, 1 + sum(islandSize[x] for x in nbGps))
        return res
