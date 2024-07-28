class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)
        prev, val = nums[0], max(nums[:2])
        for i in range(2, len(nums)):
            prev, val = val, max(prev + nums[i], val)
        return val
