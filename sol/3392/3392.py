class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        return sum(
            (nums[i] + nums[i + 2]) * 2 == nums[i + 1]
            for i in range(len(nums) - 2)
        )
