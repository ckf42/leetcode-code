class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        M = 10 ** 9 + 7
        m = len(grid)
        n = len(grid[0])
        memo = [[0] * k for _ in range(n)]
        ptr = grid[0][0] % k
        memo[0][ptr] = 1
        for j in range(1, n):
            ptr = (ptr + grid[0][j]) % k
            memo[j][ptr] = 1
        for i in range(1, m):
            buff = memo[0][:]
            for r in range(k):
                memo[0][(r + grid[i][0]) % k] = buff[r]
            for j in range(1, n):
                buff = memo[j][:]
                for r in range(k):
                    memo[j][(r + grid[i][j]) % k] = (memo[j - 1][r] + buff[r]) % M
        return memo[n - 1][0]

