class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        counter = 0
        for i in range(n - 2):
            if nums[i] == 0:
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                counter += 1
        return counter if nums[-2] == 1 == nums[-1] else -1
