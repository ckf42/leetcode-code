class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        total = sum(nums)
        if n == total:
            return 0
        swapCount = sum(x == 0 for x in nums[:total])
        minSwap = swapCount
        e = total
        for s in range(1, n):
            swapCount += (nums[e] == 0) - (nums[s - 1] == 0)
            minSwap = min(minSwap, swapCount)
            e = (e + 1) % n
        return minSwap
