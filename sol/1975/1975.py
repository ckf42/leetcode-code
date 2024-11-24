class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        res = sum(abs(x) for r in matrix for x in r)
        hasSingleNeg = sum(x < 0 for r in matrix for x in r) & 1
        if hasSingleNeg:
            res -= 2 * min(abs(x) for r in matrix for x in r)
        return res
