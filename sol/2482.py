class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        oneRow = list(0 for _ in range(m))
        oneCol = list(0 for _ in range(n))
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    oneRow[i] += 1
                    oneCol[j] += 1
        for i in range(m):
            for j in range(n):
                grid[i][j] = (oneRow[i] + oneCol[j]) * 2 - m - n
        return grid
