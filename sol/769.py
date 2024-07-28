class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        res = 0
        maxVal = 0
        for i, x in enumerate(arr):
            maxVal = max(maxVal, x)
            if i == maxVal:
                res += 1
        return res
