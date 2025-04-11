class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        minval = min(nums)
        if minval < k:
            return -1
        return len(frozenset(x for x in nums if x > k))
