from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq = defaultdict(int)
        n = len(nums)
        res = 0
        s = 0
        for e in range(n):
            freq[nums[e]] += 1
            while freq[nums[e]] > k:
                freq[nums[s]] -= 1
                s += 1
            res = max(res, e - s + 1)
        return res
