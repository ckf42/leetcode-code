class Solution:
    def getSum(self, a: int, b: int) -> int:
        m = 0xfff
        a &= m
        b &= m
        while b != 0:
            a, b = (a ^ b) & m, ((a & b) << 1) & m
        if a & 0x800:
            a = ~((~a) & m)
        return a
