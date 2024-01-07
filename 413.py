class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return 0
        res = 0
        prev = 0
        prevDiff = nums[1] - nums[0]
        for i in range(2, n):
            currDiff = nums[i] - nums[i - 1]
            val = 0
            if currDiff == prevDiff:
                val = prev + 1
            res += val
            prev = val
            prevDiff = currDiff
        return res
