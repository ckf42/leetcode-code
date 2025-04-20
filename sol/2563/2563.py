class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        l = n
        r = n - 1
        for i, x in enumerate(nums):
            l = max(i + 1, l)
            while l > i + 1 and x + nums[l - 1] >= lower:
                l -= 1
            while r >= l and x + nums[r] > upper:
                r -= 1
            if r <= i:
                break
            res += r - l + 1
        return res
