class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        res = nums[0] + nums[-1]
        for i in range(1, len(nums) // 2):
            res = max(res, nums[i] + nums[-1 - i])
        return res
