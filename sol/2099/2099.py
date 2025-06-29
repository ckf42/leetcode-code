class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        indices = sorted(range(n), key=lambda i: nums[i], reverse=True)[:k]
        indices.sort()
        return [nums[i] for i in indices]
