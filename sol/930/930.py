class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        res = 0
        prefixSum = 0
        sumCount = {0: 1}
        for n in nums:
            prefixSum += n
            res += sumCount.get(prefixSum - goal, 0)
            sumCount[prefixSum] = sumCount.get(prefixSum, 0) + 1
        return res
