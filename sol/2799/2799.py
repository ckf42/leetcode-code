class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        totalUniq = len(frozenset(nums))
        freq = [0] * 2001
        l = 0
        res = 0
        uqCount = 0
        for r in range(n):
            freq[nums[r]] += 1
            if freq[nums[r]] == 1:
                uqCount += 1
            while l <= r and uqCount == totalUniq:
                freq[nums[l]] -= 1
                if freq[nums[l]] == 0:
                    uqCount -= 1
                l += 1
            res += l
        return res
