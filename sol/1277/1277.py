class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        memo = [0] * n
        res = 0
        for j in range(n):
            if matrix[0][j] == 1:
                memo[j] = 1
                res += 1
        for i in range(1, m):
            buff = memo[0]
            memo[0] = matrix[i][0]
            res += memo[0]
            for j in range(1, n):
                newBuff = 0
                if matrix[i][j] == 1:
                    newBuff = min(buff, memo[j - 1], memo[j]) + 1
                buff, memo[j] = memo[j], newBuff
                res += memo[j]
        return res
