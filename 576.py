from functools import cache

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        modulo = int(1e9) + 7
        @cache
        def dp(i, j, remainMoves):
            if i < 0 or j < 0 or i >= m or j >= n:
                return 1
            if remainMoves <= 0:
                return 0
            return (dp(i - 1, j, remainMoves - 1) + dp(i + 1, j, remainMoves - 1)
            + dp(i, j - 1, remainMoves - 1) + dp(i, j + 1, remainMoves - 1)) % modulo

        return dp(startRow, startColumn, maxMove)
