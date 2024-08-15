class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        res = 0
        for i in range(row - 2):
            for j in range(col - 2):
                if grid[i + 1][j + 1] != 5:
                    continue
                m = 0
                rowsum = [0] * 3
                colsum = [0] * 3
                for di in range(3):
                    for dj in range(3):
                        m |= 1 << grid[i + di][j + dj]
                        rowsum[di] += grid[i + di][j + dj]
                        colsum[dj] += grid[i + di][j + dj]
                if m == 1022 \
                        and rowsum[0] == 15 and rowsum[1] == 15 and rowsum[2] == 15 \
                        and colsum[0] == 15 and colsum[1] == 15 and colsum[2] == 15 \
                        and grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15 \
                        and grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] == 15:
                    res += 1
        return res
