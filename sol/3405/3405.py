class Solution:
    c_M = 10 ** 9 + 7
    c_inv = [pow(i, -1, 10 ** 9 + 7) for i in range(1, 10 ** 5 + 1)]

    @classmethod
    def comb(cls, n: int, r: int) -> int:
        res = 1
        for i in range(r):
            res = (res * (n - i) * cls.c_inv[i]) % cls.c_M
        return res

    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return (m * self.comb(n - 1, min(k, n - 1 - k)) * pow(m - 1, n - 1 - k, self.c_M)) % self.c_M
