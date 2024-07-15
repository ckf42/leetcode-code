class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        res = sum(nums)
        for x in nums:
            y = 0
            while x != 0:
                x, r = divmod(x, 10)
                y += r
            res += x - y
        return abs(res)
