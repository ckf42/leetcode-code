class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        for i, x in enumerate(nums):
            res[i] = nums[x]
        return res
