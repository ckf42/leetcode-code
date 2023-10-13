class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return len(range(low | 1, high + 1, 2))
