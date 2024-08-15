class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        a = n >> 1
        b = m >> 1
        return (n - a) * b + a * (m - b)
