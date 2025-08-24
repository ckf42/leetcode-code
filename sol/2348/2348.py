class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = 0
        count = 0
        for x in nums:
            if x != 0:
                count = 0
            else:
                count += 1
                res += count
        return res
