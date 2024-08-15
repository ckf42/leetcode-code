class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0

        def dfs(i, j, visited):
            val = 0
            if i > 0 and (i - 1, j) not in visited and grid[i - 1][j]:
                visited.add((i - 1, j))
                val = max(val, dfs(i - 1, j, visited) + grid[i - 1][j])
                visited.remove((i - 1, j))
            if i < m - 1 and (i + 1, j) not in visited and grid[i + 1][j]:
                visited.add((i + 1, j))
                val = max(val, dfs(i + 1, j, visited) + grid[i + 1][j])
                visited.remove((i + 1, j))
            if j > 0 and (i, j - 1) not in visited and grid[i][j - 1]:
                visited.add((i, j - 1))
                val = max(val, dfs(i, j - 1, visited) + grid[i][j - 1])
                visited.remove((i, j - 1))
            if j < n - 1 and (i, j + 1) not in visited and grid[i][j + 1]:
                visited.add((i, j + 1))
                val = max(val, dfs(i, j + 1, visited) + grid[i][j + 1])
                visited.remove((i, j + 1))
            return val


        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    res = max(res, dfs(i, j, {(i, j)}) + grid[i][j])
        return res
