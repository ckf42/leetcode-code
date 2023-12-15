class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        lastEle = None
        combo = 0
        for ele in arr:
            if ele == lastEle:
                combo += 1
            else:
                combo = 1
            lastEle = ele
            if combo * 4 > n:
                return ele
