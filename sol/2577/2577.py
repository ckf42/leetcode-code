import heapq as hq

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        h = [(0, 0, 0)]
        pushed = [[False] * n for _ in range(m)]
        pushed[0][0] = True
        while len(h) != 0:
            t, i, j = hq.heappop(h)
            if i == m - 1 and j == n - 1:
                return t
            t += 1
            for ii, jj in ((i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)):
                if not (0 <= ii < m and 0 <= jj < n) or pushed[ii][jj]:
                    continue
                cost = t
                if grid[ii][jj] > t:
                    cost = grid[ii][jj] + ((grid[ii][jj] ^ t) & 1)
                hq.heappush(h, (cost, ii, jj))
                pushed[ii][jj] = True
        return -1
