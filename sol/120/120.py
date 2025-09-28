class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        memo = [0] * n
        memo[0] = triangle[0][0]
        for i in range(1, n):
            memo[i] = triangle[i][i] + memo[i - 1]
            for j in range(i - 1, 0, -1):
                memo[j] = triangle[i][j] + min(memo[j], memo[j - 1])
            memo[0] += triangle[i][0]
        return min(memo)
