class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        n = len(matrix)
        m = len(matrix[0])
        for j in range(1, m):
            matrix[0][j] += matrix[0][j - 1]
        for i in range(1, n):
            matrix[i][0] += matrix[i - 1][0]
            for j in range(1, m):
                matrix[i][j] += matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1]
        count = 0
        for r1 in range(n):
            for r2 in range(r1, n):
                rec = {0: 1}
                for c in range(m):
                    sub = matrix[r2][c] - (matrix[r1 - 1][c] if r1 > 0 else 0)
                    count += rec.get(sub - target, 0)
                    rec[sub] = rec.get(sub, 0) + 1
        return count
