class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        right = sum(grid[0]) - grid[0][0]
        res = right
        left = grid[1][0]
        for i in range(1, n):
            right -= grid[0][i]
            res = min(res, max(left, right))
            left += grid[1][i]
        return res
