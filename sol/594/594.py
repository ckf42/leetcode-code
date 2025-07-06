class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq = dict()
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        res = 0
        for a, f1 in freq.items():
            if (f2 := freq.get(a + 1, 0)) != 0:
                res = max(res, f1 + f2)
        return res
