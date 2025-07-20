class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n
        total = sum(x & 1 for x in nums)
        prev = nums[0] & 1
        count = 1
        for x in nums[1:]:
            x &= 1
            if x != prev:
                count += 1
                prev = x
        return max(total, n - total, count)
