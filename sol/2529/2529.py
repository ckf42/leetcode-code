import bisect

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)
        neg = bisect.bisect_left(nums, 0)
        pos = n - bisect.bisect(nums, 0, lo=neg)
        return max(pos, neg)
