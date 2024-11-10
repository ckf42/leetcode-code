class Solution:
    def minEnd(self, n: int, x: int) -> int:
        m = 1
        n -= 1
        res = x
        while n != 0:
            if (res & m) == 0:
                if n & 1:
                    res |= m
                n >>= 1
            m <<= 1
        return res
