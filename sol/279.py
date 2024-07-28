class Solution:
    def numSquares(self, n: int) -> int:
        # check 1
        sqrtn = int(n ** (1 / 2))
        if sqrtn ** 2 == n:
            return 1
        for i in range(1, sqrtn + 1):
            m = n - i * i
            if int(m ** (1 / 2)) ** 2 == m:
                return 2
        m = n
        while m & 3 == 0:
            m >>= 2
        if m & 7 != 7:
            return 3
        return 4
