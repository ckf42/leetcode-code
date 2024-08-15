class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        lastEle = 0
        for e in arr:
            lastEle = min(lastEle + 1, e)
        return lastEle
