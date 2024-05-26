class Solution:
    def checkRecord(self, n: int) -> int:
        if n == 1:
            return 3
        m = int(1E9) + 7
        x = [
            [1, 0, 1, 0, 1, 0],
            [1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 0, 1, 0, 0, 0],
            [0, 0, 0, 1, 0, 0]
        ]
        y = [[1 if i == j else 0 for j in range(6)] for i in range(6)]
        def mul(a, b):
            return [
                [
                    sum(a[i][k] * b[k][j] for k in range(6)) % m 
                    for j in range(6)
                ]
                for i in range(6)
            ]
        while n > 1:
            if n & 1:
                y = mul(x, y)
                n ^= 1
            x = mul(x, x)
            n >>= 1
        x = mul(x, y)
        return sum(x[i][0] for i in range(6)) % m
