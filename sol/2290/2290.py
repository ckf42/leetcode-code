from collections import deque

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        reached = [[False] * n for _ in range(m)]
        q = deque([(0, 0, 0)])
        while len(q) != 0:
            cost, i, j = q.pop()
            if i == m - 1 and j == n - 1:
                return cost
            if reached[i][j]:
                continue
            reached[i][j] = True
            for ii, jj in ((i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)):
                if not (0 <= ii < m and 0 <= jj < n) or reached[ii][jj]:
                    continue
                if grid[ii][jj]:
                    q.appendleft((cost + 1, ii, jj))
                else:
                    q.append((cost, ii, jj))
        return -1

