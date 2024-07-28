class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ptr = 0
        while ptr < n and k > 0:
            if nums[ptr] >= 0:
                break
            nums[ptr] *= -1
            k -= 1
            ptr += 1
        if k > 0:
            k &= 1
        s = sum(nums)
        if k > 0:
            if ptr == n:
                s -= nums[-1] * 2
            elif ptr > 0:
                s -= min(nums[ptr], nums[ptr - 1]) * 2
            else:
                s -= nums[0] * 2
        return s
