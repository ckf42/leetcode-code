class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        if len(nums) == 1:
            return 0 if nums[0] > threshold else 1 - (nums[0] & 1)
        l = 0
        maxlen = 0
        while True:
            while l < len(nums) and (nums[l] > threshold or nums[l] & 1 == 1):
                l += 1
            if l == len(nums):
                break
            r = l + 1
            while r < len(nums) and nums[r] <= threshold and nums[r] & 1 != nums[r - 1] & 1:
                r += 1
            maxlen = max(maxlen, r - l)
            if r == len(nums):
                break
            else:
                l = r
        return maxlen
