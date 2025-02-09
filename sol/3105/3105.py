class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        inc = 1
        dec = 1
        res = 1
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                inc += 1
                dec = 1
                res = max(res, inc)
            elif nums[i] < nums[i - 1]:
                dec += 1
                inc = 1
                res = max(res, dec)
            else:
                dec = 1
                inc = 1
        return res
