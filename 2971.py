class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        prefixSum = sum(nums)
        for x in nums[:-2]:
            if x * 2 < prefixSum:
                return prefixSum
            prefixSum -= x
        return -1
