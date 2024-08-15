class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        memo = [1 if matrix[0][j] == '1' else 0 for j in range(n)]
        maxside = max(memo)
        for i in range(1, m):
            leftup = memo[0]
            memo[0] = 1 if matrix[i][0] == '1' else 0
            maxside = max(maxside, memo[0])
            for j in range(1, n):
                leftup, memo[j] = memo[j], (1 + min(leftup, memo[j - 1], memo[j]) if matrix[i][j] == '1' else 0)
                maxside = max(maxside, memo[j])
        return maxside * maxside


