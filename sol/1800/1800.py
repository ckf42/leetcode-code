class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res = 0
        currSum = 0
        prev = nums[0] - 1
        for x in nums:
            if x <= prev:
                currSum = 0
            currSum += x
            res = max(res, currSum)
            prev = x
        return res
