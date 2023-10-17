class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        memo = [0] * n
        memo[0] = 1
        for i in range(1, n):
            if obstacleGrid[0][i] == 1:
                break
            memo[i] = 1
        for i in range(1, m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    memo[j] = 0
                else:
                    memo[j] += 0 if j == 0 else memo[j - 1]
        return memo[-1]
