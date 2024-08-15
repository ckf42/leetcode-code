from collections import Counter

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        c = Counter(nums)
        res = 0
        for v in c.values():
            if v == 1:
                return -1
            res += (v + 2) // 3
        return res
