class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 1:
            return grid[0][0]
        minvals = [sorted((grid[i][j], j) for j in range(3)) for i in range(n)]
        for i in range(n):
            for j in range(3, n):
                if grid[i][j] < minvals[i][0][0]:
                    minvals[i][0], minvals[i][1], minvals[i][2] = (grid[i][j], j), minvals[i][0], minvals[i][1]
                elif grid[i][j] < minvals[i][1][0]:
                    minvals[i][1], minvals[i][2] = (grid[i][j], j), minvals[i][1]
                elif grid[i][j] < minvals[i][2][0]:
                    minvals[i][2] = (grid[i][j], j)
        for i in range(1, n):
            for j in range(3):
                minvals[i][j] = (
                    minvals[i][j][0] + min((x[0] for x in minvals[i - 1] if x[1] != minvals[i][j][1])),
                    minvals[i][j][1])
        return min(x[0] for x in minvals[n - 1])
