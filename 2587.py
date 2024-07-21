class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        prefix = 0
        for i, x in enumerate(nums):
            prefix += x
            if prefix <= 0:
                return i
        return len(nums)

