class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        res = 0
        for i in range(n):
            res += fruits[i][i]
            fruits[i][i] = 0
        m = (n + 1) // 2
        memo = [0] * m
        memo[0] = fruits[0][n - 1]
        for i in range(1, n):
            l = min(i + 1, n - i)
            memo[:i + 1] = [max(memo[max(0, j - 1) : min(j + 1, m) + 1]) + fruits[i][n - 1 - j] for j in range(l)]
        res += memo[0]
        memo = [0] * m
        memo[0] = fruits[n - 1][0]
        for i in range(1, n):
            l = min(i + 1, n - i)
            memo[:i + 1] = [max(memo[max(0, j - 1) : min(j + 1, m) + 1]) + fruits[n - 1 - j][i] for j in range(l)]
        res += memo[0]
        return res
