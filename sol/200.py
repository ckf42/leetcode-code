class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        visited = set()

        def floodfill(i, j):
            if (i, j) in visited:
                return
            visited.add((i, j))
            if i > 0 and grid[i - 1][j] == '1':
                floodfill(i - 1, j)
            if j > 0 and grid[i][j - 1] == '1':
                floodfill(i, j - 1)
            if i < m - 1 and grid[i + 1][j] == '1':
                floodfill(i + 1, j)
            if j < n - 1 and grid[i][j + 1] == '1':
                floodfill(i, j + 1)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and (i, j) not in visited:
                    res += 1
                    floodfill(i, j)
        return res
