import numpy as np

class Solution:
    def numOfWays(self, n: int) -> int:
        m = int(1e9) + 7
        if n == 1:
            return 12
        x = np.array([[0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0],
                      [0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0],
                      [0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1],
                      [0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1],
                      [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1],
                      [1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0],
                      [0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1],
                      [1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1],
                      [1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                      [1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0],
                      [0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0],
                      [0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0]],
                     dtype=np.uint64)
        y = np.eye(12, dtype=np.uint64)
        n -= 1
        while n > 1:
            if n & 1:
                np.matmul(x, y, out=y)
                np.mod(y, m, out=y)
            np.matmul(x, x, out=x)
            np.mod(x, m, out=x)
            n //= 2
        np.matmul(x, y, out=y)
        return sum(y.flatten().tolist()) % m


