class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        memo = [set(range(m)), set()]
        r, w = 0, 1
        for j in range(n - 1):
            memo[w].clear()
            while len(memo[r]) != 0:
                i = memo[r].pop()
                if i != 0 and grid[i][j] < grid[i - 1][j + 1]:
                    memo[w].add(i - 1)
                if grid[i][j] < grid[i][j + 1]:
                    memo[w].add(i)
                if i != m - 1 and grid[i][j] < grid[i + 1][j + 1]:
                    memo[w].add(i + 1)
            if len(memo[w]) == 0:
                return j
            r ^= 1
            w ^= 1
        return n - 1
