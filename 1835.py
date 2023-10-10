class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        res1, res2 = 0, 0
        for n in arr1:
            res1 ^= n
        for n in arr2:
            res2 ^= n
        return res1 & res2
