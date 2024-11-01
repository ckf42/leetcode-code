from math import isqrt

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums = sorted(frozenset(nums))
        memo = {
            x: 1
            for x in nums
        }
        res = 1
        for x in nums:
            if (q := isqrt(x)) ** 2 == x:
                memo[x] = memo.get(q, 0) + 1
                res = max(res, memo[x])
        return res if res != 1 else -1
