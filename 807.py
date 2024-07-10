class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        skylines = (
            tuple(max(r) for r in grid),
            tuple(max(c) for c in zip(*grid))
        )  # hori, vert
        return sum(
            min(skylines[0][i], skylines[1][j])
            for i in range(n)
            for j in range(n)
        ) - sum(sum(r) for r in grid)
