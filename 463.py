class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        res = 0
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    continue
                res += 4
                if i > 0 and grid[i - 1][j] == 1:
                    res -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    res -= 2
        return res
