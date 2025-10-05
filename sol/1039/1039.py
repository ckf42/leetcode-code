class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        if n == 3:
            return values[0] * values[1] * values[2]
        memo = [[0] * n for _ in range(n)]  # [i, j]
        for i in range(n - 2):
            memo[i][i + 2] = values[i] * values[i + 1] * values[i + 2]
        for l in range(3, n):
            for i in range(n - l):
                memo[i][i + l] = min(
                    memo[i][j] + memo[j][i + l] + values[i] * values[i + l] * values[j]
                    for j in range(i + 1, i + l)
                )
        return memo[0][n - 1]
