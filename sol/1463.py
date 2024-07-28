class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        memo = [[[-1] * c for __ in range(c)] for _ in range(r)]
        memo[0][0][c - 1] = grid[0][0] + grid[0][c - 1]
        for i in range(1, r):
            for newj in range(c - 1):
                for newk in range(newj + 1, c):
                    count = grid[i][newj] + grid[i][newk]
                    for oldj in (newj - 1, newj, newj + 1):
                        if oldj < 0 or oldj >= c:
                            continue
                        for oldk in (newk - 1, newk, newk + 1):
                            if oldk <= oldj or oldk >= c or memo[i - 1][oldj][oldk] == -1:
                                continue
                            memo[i][newj][newk] = max(
                                memo[i][newj][newk],
                                memo[i - 1][oldj][oldk] + count
                            )
        return max(memo[r - 1][j][k] for j in range(c - 1) for k in range(j + 1, c))
