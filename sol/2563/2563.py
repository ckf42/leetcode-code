import bisect

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        s = n
        e = n
        res = 0
        for i in range(n):
            s = bisect.bisect_left(nums, lower - nums[i], lo=i + 1, hi=s)
            e = bisect.bisect_right(nums, upper - nums[i], lo=i, hi=e)
            if e <= i:
                break
            res += e - s
        return res
