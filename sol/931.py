class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(1, n):
            matrix[i][0] += min(matrix[i - 1][0:2])
            for j in range(1, n - 1):
                matrix[i][j] += min(matrix[i - 1][j - 1:j + 2])
            matrix[i][n - 1] += min(matrix[i - 1][n - 2:n])
        return min(matrix[-1])
