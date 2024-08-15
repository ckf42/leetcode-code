class Solution:
    @staticmethod
    def matmul(x, y, m):
        return list(list(sum(x[i][k] * y[k][j]
                             for k in range(5)) % m
                         for j in range(5))
                    for i in range(5))

    def countVowelPermutation(self, n: int) -> int:
        if n == 1:
            return 5
        n -= 1
        m = int(1e9) + 7
        y = list(list(1 if i == j else 0 for j in range(5)) for i in range(5))
        x = [[0, 1, 1, 0, 1], [1, 0, 1, 0, 0], [0, 1, 0, 1, 0], [0, 0, 1, 0, 0], [0, 0, 1, 1, 0]]
        while n > 1:
            if n & 1:
                y = self.matmul(x, y, m)
                n ^= 1
            x = self.matmul(x, x, m)
            n >>= 1
        return sum(sum(l) for l in self.matmul(x, y, m)) % m
