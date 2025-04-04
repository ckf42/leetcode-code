class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        maxVal = 0
        maxEle = 0
        maxDiff = 0
        for x in nums:
            if (v := maxDiff * x) > maxVal:
                maxVal = v
            if (v := maxEle - x) > maxDiff:
                maxDiff = v
            if x > maxEle:
                maxEle = x
        return maxVal
