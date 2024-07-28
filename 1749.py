class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        pos = 0
        neg = 0
        currPos = 0
        currNeg = 0
        for x in nums:
            currPos = max(0, currPos + x)
            currNeg = max(0, currNeg - x)
            pos = max(pos, currPos)
            neg = max(neg, currNeg)
        return max(pos, neg)
