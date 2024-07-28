class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            n = -n
            x = 1.0 / x
        y = 1
        while n > 1:
            if n & 1:
                y *= x
                n ^= 1
            x *= x
            n >>= 1
        return x * y
