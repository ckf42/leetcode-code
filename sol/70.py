class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        prev, val = 1, 1
        for i in range(n - 1):
            prev, val = val, prev + val
        return val

    # def matmul(self, x, y):
    #     return list(list(sum(x[i][k] * y[k][j] for k in range(2))
    #                      for j in range(2))
    #                 for i in range(2))

    # def climbStairs(self, n: int) -> int:
    #     if n <= 1:
    #         return 1
    #     x = [[1, 1], [1, 0]]
    #     y = [[1, 0], [0, 1]]
    #     while n > 1:
    #         if n & 1:
    #             y = self.matmul(x, y)
    #             n ^= 1
    #         x = self.matmul(x, x)
    #         n >>= 1
    #     x = self.matmul(x, y)
    #     return sum(x[1])
