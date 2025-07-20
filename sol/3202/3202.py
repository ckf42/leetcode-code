class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n <= 2:
            return n
        for i in range(n):
            nums[i] %= k
        res = 1
        for rem in range(k):
            memo = [0] * k
            for x in nums:
                memo[x] = memo[(rem + k - 1 - x) % k] + 1
            res = max(res, *memo)
        return res
