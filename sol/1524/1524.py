class Solution:
    m = 10 ** 9 + 7
    def numOfSubarrays(self, arr: List[int]) -> int:
        e, o = 0, 0
        res = 0
        for x in arr:
            e += 1
            if x & 1:
                e, o = o, e
            res += o
        return res % self.m
