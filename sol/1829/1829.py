class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        res = [0] * n
        res[n - 1] = ((1 << maximumBit) - 1) ^ nums[0]
        for i in range(n - 2, -1, -1):
            res[i] = res[i + 1] ^ nums[n - 1 - i]
        return res
