class Solution:
    def totalMoney(self, n: int) -> int:
        q, r = divmod(n, 7)
        return r * (r + 1 + 2 * q) // 2 + (7 * q * (q + 7) // 2 if q != 0 else 0)
