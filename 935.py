import numpy as np

class Solution:
    M = int(1e9) + 7
    numberPad = (
        (3, 1),  # 0
        *(divmod(i - 1, 3) for i in range(1, 10))
    )
    transitionList = None
    def __init__(self):
        if self.transitionList is None:
            self.transitionList = tuple(
                tuple(
                    j
                    for j in range(10)
                    if sorted((abs(Solution.numberPad[i][0] - Solution.numberPad[j][0]), 
                               abs(Solution.numberPad[i][1] - Solution.numberPad[j][1]))) == [1, 2]
                )
                for i in range(10)
            )  # ((4, 6), (6, 8), (7, 9), (4, 8), (0, 3, 9), (), (0, 1, 7), (2, 6), (1, 3), (2, 4))

    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        x = np.zeros((10, 10), dtype=np.int64)
        for i in range(10):
            for j in self.transitionList[i]:
                x[i][j] = 1
        y = np.identity(10, dtype=np.int64)
        n -= 1
        while n > 1:
            if n & 1:
                np.matmul(x, y, out=y)
                np.remainder(y, self.M, out=y)
            np.matmul(x, x, out=x)
            np.remainder(x, self.M, out=x)
            n >>= 1
        np.matmul(x, y, out=x)
        np.remainder(x, self.M, out=x)
        return int(np.sum(x)) % self.M


