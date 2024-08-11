
class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        return not all(
            sum(
                grid[i + di][j + dj] == 'B'
                for di in range(2)
                for dj in range(2)
            ) == 2
            for i in range(2)
            for j in range(2)
        )
