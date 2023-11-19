class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        winStart = 0
        winSum = 0
        for targetIdx in range(len(nums)):
            target = nums[targetIdx]
            winSum += target
            if (targetIdx - winStart + 1) * target - winSum > k:
                winSum -= nums[winStart]
                winStart += 1
        return len(nums) - winStart
