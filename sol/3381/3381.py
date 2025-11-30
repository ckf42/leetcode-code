class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        memo = [0] * k
        winsum = sum(nums[:k])
        memo[k - 1] = winsum
        res = memo[k - 1]
        for i in range(k, n):
            winsum += nums[i] - nums[i - k]
            j = i % k
            memo[j] = max(memo[j] + winsum, winsum)
            res = max(res, memo[j])
        return res
