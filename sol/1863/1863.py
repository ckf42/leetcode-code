class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for x in nums:
            res |= x
        return res * (1 << (n - 1))
