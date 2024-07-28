class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        h = dict()
        for x in nums:
            h[x] = h.get(x, 0) + 1
        res = 0
        for x, c in h.items():
            if c == 1:
                res += x
        return res
