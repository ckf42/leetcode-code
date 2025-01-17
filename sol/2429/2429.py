class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        k = num2.bit_count()
        l = num1.bit_count()
        m = 1
        while k > l:
            while (num1 & m) != 0:
                m <<= 1
            num1 ^= m
            l += 1
        m = 1
        while k < l:
            while (num1 & m) == 0:
                m <<= 1
            num1 ^= m
            l -= 1
        return num1
