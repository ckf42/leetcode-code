class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [None] * n
        totalSum = sum(nums)
        for i in range(n):
            res[i] = totalSum - (n - 2 * i) * nums[i]
            totalSum -= 2 * nums[i]
        return res
