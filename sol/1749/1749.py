class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        total = 0
        maxi = 0
        mini = 0
        for x in nums:
            total += x
            maxi = max(maxi, total)
            mini = min(mini, total)
        return maxi - mini
