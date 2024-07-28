class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        res = [False] * len(nums)
        x = 0
        for i, b in enumerate(nums):
            x <<= 1
            x |= b
            x %= 5
            res[i] = x == 0
        return res
