class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        col = [False] * n
        row = [False] * m
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    col[i] = True
                    row[j] = True
        return (next(i for i in range(n - 1, -1, -1) if col[i]) - next(i for i in range(n) if col[i]) + 1) \
            * (next(j for j in range(m - 1, -1, -1) if row[j]) - next(j for j in range(m) if row[j]) + 1)
