class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        for d in range(-n, 0):
            buff = [grid[j][j - d] for j in range(n + d)]
            buff.sort()
            for j in range(n + d):
                grid[j][j - d] = buff[j]
        for d in range(n + 1):
            buff = [grid[j + d][j] for j in range(n - d)]
            buff.sort(reverse=True)
            for j in range(n - d):
                grid[j + d][j] = buff[j]
        return grid
