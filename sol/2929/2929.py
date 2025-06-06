class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > limit * 3:
            return 0
        if n < limit:
            return (n + 1) * (n + 2) // 2
        elif n < limit * 2:
            return (3 * limit * (limit + 2) - (n * 2 - limit * 3) ** 2) // 4 + 1
        k = n - limit * 3 - 2
        return k * (k + 1) // 2
