class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        p = 0
        res = 0
        idx = {0: -1}
        for i, n in enumerate(nums):
            p += 1 if n == 1 else -1
            if p not in idx:
                idx[p] = i
            else:
                res = max(res, i - idx[p])
        return res
