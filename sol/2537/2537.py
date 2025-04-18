from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        seen = defaultdict(int)
        l = 0
        count = 0
        for r, x in enumerate(nums):
            count += seen[x]
            seen[x] += 1
            while count >= k:
                seen[nums[l]] -= 1
                count -= seen[nums[l]]
                l += 1
            res += l
        return res
