class Solution:
    m = 10 ** 9 + 7
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        res = 1
        prev = -1
        for i, x in enumerate(nums):
            if x != 1:
                continue
            if prev != -1:
                res = (res * (i - prev)) % self.m
            prev = i
        return res if prev != -1 else 0
