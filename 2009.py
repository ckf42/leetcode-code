class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(frozenset(nums))
        ans = n
        e = 0
        for i, x in enumerate(nums):
            while e < len(nums) and nums[e] < x + n:
                e += 1
            ans = min(ans, n - e + i)
        return ans
