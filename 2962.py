class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        maxele = max(nums)
        indices = (-1,) + tuple(i for i, x in enumerate(nums) if x == maxele)
        if len(indices) <= k:
            return 0
        res = 0
        for i in range(1, len(indices) - k + 1):
            res += (indices[i] - indices[i - 1]) * (n - indices[i + k - 1])
        return res
