class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        rg = {0: 1}
        for x in nums:
            newRg = dict()
            for val, freq in rg.items():
                newRg[val + x] = newRg.get(val + x, 0) + freq
                newRg[val - x] = newRg.get(val - x, 0) + freq
            rg = newRg
        return rg.get(target, 0)
