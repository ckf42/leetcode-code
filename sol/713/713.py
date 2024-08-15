class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = 0
        prod = 1
        s = 0
        for e in range(n):
            prod *= nums[e]
            while s <= e and prod >= k:
                prod //= nums[s]
                s += 1
            res += e - s + 1
        return res
