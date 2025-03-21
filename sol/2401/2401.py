class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        res = 1
        n = len(nums)
        mask = nums[0]
        l = 0
        for r in range(1, n):
            while l < r and (mask & nums[r]) != 0:
                mask ^= nums[l]
                l += 1
            mask |= nums[r]
            res = max(res, r - l + 1)
        return res
