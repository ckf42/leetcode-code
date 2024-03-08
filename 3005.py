from collections import Counter

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        c = Counter(nums)
        m = max(c.values())
        return sum(1 for v in c.values() if v == m) * m