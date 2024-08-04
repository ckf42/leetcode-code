class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        memo = [[[0] * n for _ in range(n)] for __ in range(n)]
        for i in range(n):
            for k in range(n):
                memo[i][i][k] = (k + 1) ** 2
        for l in range(2, n + 1):
            for j in range(l - 1, n):
                i = j - l + 1
                for k in range(i + 1):
                    p = (k + 1) ** 2 + memo[i + 1][j][0]
                    for m in range(i + 1, j + 1):
                        if boxes[m] == boxes[i]:
                            p = max(p, memo[m][j][k + 1] + memo[i + 1][m - 1][0])
                    memo[i][j][k] = p
        return memo[0][n - 1][0]
