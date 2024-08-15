class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        lastMinKIdx = -1
        lastMaxKIdx = -1
        lastObIdx = -1
        for e in range(len(nums)):
            if not (minK <= nums[e] <= maxK):
                lastObIdx = e
            else:
                if nums[e] == minK:
                    lastMinKIdx = e
                if nums[e] == maxK:
                    lastMaxKIdx = e
                res += max(0, min(lastMinKIdx, lastMaxKIdx) - lastObIdx)
        return res
