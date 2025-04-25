from math import comb

class Solution:
    PrimeTable = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97)
    def idealArrays(self, n: int, maxValue: int) -> int:
        M = 10 ** 9 + 7
        res = 0
        for val in range(1, maxValue + 1):
            count = 1
            for p in self.PrimeTable:
                exponent = 0
                while val % p == 0:
                    val //= p
                    exponent += 1
                count = (count * comb(n + exponent - 1, exponent)) % M
                if val == 1:
                    break
            if val != 1:
                count = (count * n) % M
            res = (res + count) % M
        return res
