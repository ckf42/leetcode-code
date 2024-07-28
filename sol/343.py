class Solution:
    precomp = (1, 2, 4, 6, 9, 12, 18, 27, 36)
    def integerBreak(self, n: int) -> int:
        if n <= 10:
            return self.precomp[n - 2]
        q, n = divmod(n - 7, 3)
        return (3 ** q) * self.precomp[n + 5]
