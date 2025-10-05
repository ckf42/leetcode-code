class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums) - 1
        coeff = 1
        res = nums[0]
        for i, x in enumerate(nums[1:]):
            coeff = coeff * (n - i) // (i + 1)
            res = (res + coeff % 10 * x) % 10
        return res
