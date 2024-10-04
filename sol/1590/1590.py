class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        remainder = sum(nums) % p
        if remainder == 0:
            return 0
        d = {0: -1}
        tot = 0
        res = n
        for i, x in enumerate(nums):
            tot = (tot + x) % p
            j = d.get((tot - remainder + p) % p, -2)
            if j != -2:
                res = min(res, i - j)
            d[tot] = i
        return res if res != n else -1
