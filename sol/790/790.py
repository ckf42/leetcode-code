class Solution:
    M = 10 ** 9 + 7
    Table = [0] * 1001
    def __init__(self):
        self.Table[0] = 1
        self.Table[1] = 1
        self.Table[2] = 2
    @classmethod
    def compute(cls, n):
        # OEIS A052980
        if cls.Table[n] == 0:
            cls.compute(n - 1)
            cls.Table[n] = (cls.Table[n - 1] * 2 + cls.Table[n - 3]) % cls.M
    def numTilings(self, n: int) -> int:
        if n < 0:
            return 0
        self.compute(n)
        return self.Table[n]
