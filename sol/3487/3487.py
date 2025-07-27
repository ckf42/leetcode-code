class Solution:
    def maxSum(self, nums: List[int]) -> int:
        m = max(nums)
        if m < 0:
            return m
        return sum(frozenset(x for x in nums if x >= 0))
