class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        currSum = 0
        res = 0
        for x in nums[:-1]:
            currSum += x
            res += currSum >= total - currSum
        return res
