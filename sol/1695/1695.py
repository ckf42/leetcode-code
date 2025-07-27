class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        prevIdx = dict()
        l = -1  # (l, r]
        total = 0
        for r, x in enumerate(nums):
            if (idx := prevIdx.get(x, -1)) > l:
                total -= sum(nums[l + 1:idx + 1])
                l = idx
            total += x
            prevIdx[x] = r
            res = max(res, total)
        return res
