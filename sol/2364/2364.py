from collections import Counter

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        h = Counter(i - x for i, x in enumerate(nums))
        n = len(nums)
        return n * (n - 1) // 2 - sum(v * (v - 1) // 2 for v in h.values())
