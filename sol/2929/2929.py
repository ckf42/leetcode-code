class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > limit * 3:
            return 0
        return sum(
            max(0, min(x, limit) - max(0, x - limit) + 1)
            for x in range(max(0, n - limit), min(n, limit * 2) + 1))
