class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        lastMinKIdx = -1
        lastMaxKIdx = -1
        lastObIdx = -1
        for i, x in enumerate(nums):
            if not (minK <= x <= maxK):
                lastObIdx = i
            else:
                if x == minK:
                    lastMinKIdx = i
                if x == maxK:
                    lastMaxKIdx = i
                res += max(0, min(lastMinKIdx, lastMaxKIdx) - lastObIdx)
        return res
