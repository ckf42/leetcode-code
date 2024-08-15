from collections import defaultdict

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        res = 0
        h = defaultdict(int)
        h[0] = 1
        prefix = 0
        for x in nums:
            prefix ^= x
            res += h[prefix]
            h[prefix] += 1
        return res
