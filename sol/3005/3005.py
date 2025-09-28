from collections import Counter

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        c = Counter(nums)
        m = max(c.values())
        return sum(v == m for v in c.values()) * m
