class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vSegLen = [[0] * m for _ in range(n)]
        hSegLen = [[0] * m for _ in range(n)]
        for i in range(n):
            hSegLen[i][0] = grid[i][0]
            for j in range(1, m):
                if grid[i][j] != 0:
                    hSegLen[i][j] = hSegLen[i][j - 1] + 1
        for j in range(m):
            vSegLen[0][j] = grid[0][j]
            for i in range(1, n):
                if grid[i][j] != 0:
                    vSegLen[i][j] = vSegLen[i - 1][j] + 1
        res = 0
        for d in range(n + m - 2, -1, -1):
            for i in range(min(n - 1, d), max(-1, d - m), -1):
                j = d - i
                if min(i, j) + 1 < res:
                    continue
                for l in range(min(hSegLen[i][j], vSegLen[i][j]), 0, -1):
                    if min(hSegLen[i - l + 1][j], vSegLen[i][j - l + 1]) >= l:
                        res = max(res, l)
                        break
        return res ** 2
