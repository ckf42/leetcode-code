class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxseq = 0
        res = 0
        for x in nums:
            if x == 0:
                res = max(res, maxseq)
                maxseq = 0
            else:
                maxseq += 1
        return max(res, maxseq)
