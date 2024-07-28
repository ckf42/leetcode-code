class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        m = max(nums)
        freq = [0] * (m + 1)
        for x in nums:
            freq[x] += 1
        res = 0
        for i in range(m):
            if freq[i] > 1:
                res += freq[i] - 1
                freq[i + 1] += freq[i] - 1
        res += freq[m] * (freq[m] - 1) // 2
        return res
