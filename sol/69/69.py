class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
           return x
        if x <= 3:
            return 1
        x0 = x
        x1 = x // 2
        while x0 > x1:
            x0 = x1
            x1 = (x0 * x0 + x) // (2 * x0)
        return x0
