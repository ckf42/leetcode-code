class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)]
        for i, j in walls:
            grid[i][j] = 1
        for i, j in guards:
            grid[i][j] = 6
            for ii in range(i - 1, -1, -1):
                if grid[ii][j] & 3:
                    break
                grid[ii][j] |= 2
            for ii in range(i + 1, m):
                if grid[ii][j] & 3:
                    break
                grid[ii][j] |= 2
            for jj in range(j - 1, -1, -1):
                if grid[i][jj] & 5:
                    break
                grid[i][jj] |= 4
            for jj in range(j + 1, n):
                if grid[i][jj] & 5:
                    break
                grid[i][jj] |= 4
        return sum(sum(x == 0 for x in r) for r in grid)

