class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        maxVal = 0
        maxDiff = 0
        maxNum = 0
        for n in nums:
            maxVal = max(maxVal, maxDiff * n)
            maxDiff = max(maxDiff, maxNum - n)
            maxNum = max(maxNum, n)
        return maxVal

