from itertools import accumulate

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        minval = min(nums) - k
        maxval = max(nums) + k
        memo = [0] * (maxval - minval + 2)
        for x in nums:
            memo[x - k - minval] += 1
            memo[x + k + 1 - minval] -= 1
        return max(accumulate(memo))
