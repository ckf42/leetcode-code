from itertools import accumulate

class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if len(nums) <= k * 2:
            return (-1,) * len(nums)
        segLen = k * 2 + 1
        endSeg = (-1,) * k
        return endSeg + tuple(
            x // segLen
            for x in accumulate(
                range(k + 1, len(nums) - k),
                func=(lambda x, y: x + nums[y + k] - nums[y - k - 1]),
                initial=sum(nums[:segLen]))) + endSeg
